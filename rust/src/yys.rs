use std::fs;
use std::path::Path;
use std::io::{self, Write};

// 硬编码的 main.rs 绝对路径
const MAIN_RS: &str = "/home/Qaaxaap/Documents/Qaaxaap-code/rust/src/main.rs";

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
    
    // 1. 创建文件（如果不存在）
    if !Path::new(filename).exists() {
        fs::write(filename, "")?;
        println!("创建文件: {}", filename);
    }
    
    // 2. 在硬编码的 main.rs 第一行添加 mod 语句
    let main_rs_path = Path::new(MAIN_RS);
    if main_rs_path.exists() {
        println!("找到 main.rs 文件: {}", MAIN_RS);
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
    } else {
        eprintln!("错误: {} 不存在 (检查路径是否正确)", MAIN_RS);
        eprintln!("当前工作目录: {:?}", std::env::current_dir()?);
        std::process::exit(1);
    }
    
    Ok(())
}

fn delete_file_and_remove_mod(filename: &str) -> io::Result<()> {
    let mod_name = filename.trim_end_matches(".rs");
    let mod_statement = format!("mod {};", mod_name);
    
    // 1. 删除文件（如果存在）
    if Path::new(filename).exists() {
        fs::remove_file(filename)?;
        println!("删除文件: {}", filename);
    } else {
        println!("文件 {} 不存在", filename);
    }
    
    // 2. 从硬编码的 main.rs 中移除 mod 语句
    let main_rs_path = Path::new(MAIN_RS);
    if main_rs_path.exists() {
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
    } else {
        eprintln!("错误: {} 不存在 (检查路径是否正确)", MAIN_RS);
        eprintln!("当前工作目录: {:?}", std::env::current_dir()?);
        std::process::exit(1);
    }
    
    Ok(())
}
