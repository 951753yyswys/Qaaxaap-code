use std::fs;
use std::path::{Path, PathBuf};
use std::process::{Command, exit};
use std::io::{self, Write};
use std::thread::sleep;
use std::time::Duration;

// 硬编码的 main.rs 绝对路径
const MAIN_RS: &str = "/home/Qaaxaap/Documents/Qaaxaap-code/rust/src/main.rs";
const OI_RS: &str = "/home/Qaaxaap/Documents/Qaaxaap-code/rust/src/OI.rs"; // OI.rs 的路径

fn main() -> io::Result<()> {
    let args: Vec<String> = std::env::args().collect();
    
    if args.len() < 3 {
        eprintln!("用法: yys {{new|del}} 文件名");
        eprintln!("注意：文件名可以带或不带 .rs 后缀");
        std::process::exit(1);
    }
    
    let command = &args[1];
    let mut filename = args[2].clone();
    
    // 如果没有 .rs 后缀，自动添加
    if !filename.ends_with(".rs") {
        filename.push_str(".rs");
    }
    
    match command.as_str() {
        "new" => create_file_and_add_mod(&filename)?,
        "del" => delete_file_and_remove_mod(&filename)?,
        _ => {
            eprintln!("未知命令: {}", command);
            std::process::exit(1);
        }
    }
    
    Ok(())
}

fn create_file_and_add_mod(filename: &str) -> io::Result<()> {
    // 提取模块名（去掉 .rs 后缀）
    let mod_name = filename.trim_end_matches(".rs");

    // 获取 main.rs 所在的目录路径
    let main_rs_path = Path::new(MAIN_RS);
    if !main_rs_path.exists() {
        eprintln!("错误: {} 不存在 (检查路径是否正确)", MAIN_RS);
        std::process::exit(1);
    }
    let main_dir = main_rs_path.parent().expect("无法获取 main.rs 所在目录");

    // 创建目标文件路径
    let file_path = main_dir.join(filename);

    // 1. 创建文件（如果不存在），如果不存在则从 OI.rs 复制
    if !file_path.exists() {
        // 执行 cp 命令，复制 OI.rs 到目标文件
        let output = Command::new("cp")
            .arg(OI_RS)
            .arg(&file_path)
            .output()
            .expect("执行 cp 命令失败");
        
        if !output.status.success() {
            eprintln!("复制文件失败: {}", String::from_utf8_lossy(&output.stderr));
            exit(1);
        }
        println!("从 {} 复制文件到 {}", OI_RS, file_path.display());
    }
    
    // 2. 在硬编码的 main.rs 第一行添加 mod 语句
    let content = fs::read_to_string(main_rs_path)?;
    let mut lines: Vec<&str> = content.lines().collect();
    
    // 检查是否已有该 mod 语句
    let mod_statement = format!("mod {};", mod_name);
    if !lines.iter().any(|line| line.trim() == mod_statement) {
        lines.insert(0, &mod_statement);
        let new_content = lines.join("\n");
        fs::write(main_rs_path, new_content)?;
        println!("在 {} 中添加: {}", MAIN_RS, mod_statement);
    } else {
        println!("{} 已存在于 {}", mod_statement, MAIN_RS);
    }

    // 3. 等待一秒钟，然后用 vim 打开新文件
    println!("一秒后将以 vim 打开 {}", file_path.display());
    sleep(Duration::from_secs(1));
    
    // 打开 vim 编辑器
    let mut vim_process = Command::new("vim")
        .arg(file_path)
        .spawn()
        .expect("无法启动 vim");

    // 等待 vim 退出
    let _ = vim_process.wait()
        .expect("等待 vim 退出时出错");

    Ok(())
}

fn delete_file_and_remove_mod(filename: &str) -> io::Result<()> {
    // 获取 main.rs 所在的目录路径
    let main_rs_path = Path::new(MAIN_RS);
    if !main_rs_path.exists() {
        eprintln!("错误: {} 不存在 (检查路径是否正确)", MAIN_RS);
        std::process::exit(1);
    }
    let main_dir = main_rs_path.parent().expect("无法获取 main.rs 所在目录");

    // 生成目标文件的路径
    let file_path = main_dir.join(filename);
    let mod_name = filename.trim_end_matches(".rs");
    let mod_statement = format!("mod {};", mod_name);
    
    // 1. 删除文件（如果存在）
    if file_path.exists() {
        fs::remove_file(file_path)?;
        println!("删除文件: {}", filename);
    } else {
        println!("文件 {} 不存在", filename);
    }
    
    // 2. 从硬编码的 main.rs 中移除 mod 语句
    let content = fs::read_to_string(main_rs_path)?;
    let lines: Vec<&str> = content.lines().collect();
    
    // 过滤掉匹配的行
    let new_lines: Vec<&str> = lines
        .iter()
        .filter(|line| line.trim() != mod_statement)
        .copied()
        .collect();
    
    if new_lines.len() != lines.len() {
        let new_content = new_lines.join("\n");
        fs::write(main_rs_path, new_content)?;
        println!("从 {} 中移除: {}", MAIN_RS, mod_statement);
    } else {
        println!("{} 未在 {} 中找到", mod_statement, MAIN_RS);
    }
    
    Ok(())
}

