use std::io::{self, BufRead, StdinLock};
use std::{usize, str};
/// OJ 专用 Scanner，支持读取各种类型，保持 C 的 scanf 风格
pub struct Scanner<'a> {
    stdin: StdinLock<'a>,
    buffer: Vec<u8>,
    pos: usize,
}
impl<'a> Scanner<'a> {
    pub fn new(stdin: StdinLock<'a>) -> Self {
        Self {
            stdin,
            buffer: Vec::new(),
            pos: 0,
        }
    }   
    /// 读取一个 usize（遇到非数字字符停止，不消费非数字字符）
    pub fn next_usize(&mut self) -> usize {
        self.skip_whitespace();   
        let start = self.pos;
        while self.pos < self.buffer.len() {
            let byte = self.buffer[self.pos];
            if byte.is_ascii_digit() || (self.pos == start && (byte == b'-' || byte == b'+')) {
                self.pos += 1;
            } else {
                break;
            }
        }
        if self.pos == start {
            // 没有读取到数字
            panic!("没有读取到数字");
        }
        let num_str = unsafe { str::from_utf8_unchecked(&self.buffer[start..self.pos]) };
        num_str.parse().unwrap()
    }
    /// 读取一个 f64
    pub fn next_f64(&mut self) -> f64 {
        self.skip_whitespace();   
        let start = self.pos;
        while self.pos < self.buffer.len() {
            let byte = self.buffer[self.pos];
            if byte.is_ascii_digit() || byte == b'.' || byte == b'e' || byte == b'E' || 
               byte == b'+' || byte == b'-' || (self.pos == start && (byte == b'-' || byte == b'+')) {
                self.pos += 1;
            } else {
                break;
            }
        }
        let num_str = unsafe { str::from_utf8_unchecked(&self.buffer[start..self.pos]) };
        num_str.parse().unwrap()
    }
    /// 读取一个单词（直到空白字符）
    pub fn next_string(&mut self) -> String {
        self.skip_whitespace();   
        let start = self.pos;
        while self.pos < self.buffer.len() && !self.buffer[self.pos].is_ascii_whitespace() {
            self.pos += 1;
        }
        let word = unsafe { str::from_utf8_unchecked(&self.buffer[start..self.pos]) };
        word.to_string()
    }
    /// 读取一个字符（包括空白字符）
    pub fn next_char(&mut self) -> char {
        self.ensure_buffer(1);   
        let byte = self.buffer[self.pos];
        self.pos += 1;
        byte as char
    }
    /// 跳过空白字符
    fn skip_whitespace(&mut self) {
        self.ensure_buffer(1);   
        while self.pos < self.buffer.len() && self.buffer[self.pos].is_ascii_whitespace() {
            self.pos += 1;
        }
        if self.pos >= self.buffer.len() {
            self.buffer.clear();
            self.stdin.read_until(b'\n', &mut self.buffer).unwrap();
            self.pos = 0;
            self.skip_whitespace();  // 递归跳过新行中的空白字符
        }
    }
    /// 确保缓冲区有足够数据
    fn ensure_buffer(&mut self, n: usize) {
        while self.buffer.len() - self.pos < n {
            let mut temp = Vec::new();
            self.stdin.read_until(b'\n', &mut temp).unwrap();
            self.buffer.extend(temp);
        }
    }
    /// 查看下一个字符是什么（不消费）
    pub fn peek_char(&mut self) -> Option<char> {
        self.skip_whitespace();   
        if self.pos < self.buffer.len() {
            Some(self.buffer[self.pos] as char)
        } else {
            None
        }
    }
    /// 是否还有更多输入
    pub fn has_next(&mut self) -> bool {
        self.skip_whitespace();
        self.pos < self.buffer.len()
    }
}
/// 便利函数：创建 Scanner
pub fn scanner() -> Scanner<'static> {
    let stdin = io::stdin();
    Scanner::new(stdin.lock())
}
fn dfs(u:usize,son:&Vec<Vec<usize>>,sum:&mut Vec<usize>,ans:&mut Vec<usize>,suma:usize,a:& Vec<usize>,b:&Vec<usize>)->()
{
    let mut flag=0;
    if u>1
    {
        let mut l:usize=0;
        let mut r:usize=sum.len()-1;
        let mut ed:usize=0;
        while l<=r
        {
            let mid=(l+r)/2;
            if sum[mid]<=suma {l=mid+1;ed=mid;}
            else {r=mid-1;}
        }
        ans[u]=ed;
    }
    else {sum.push(b[1]);flag=a[1];}
    for v in &son[u] 
    {
        sum.push(sum.last().unwrap()+b[*v]);
        dfs(*v,son,sum,ans,suma+a[*v]+flag,a,b);
    }
    sum.pop();
}
fn main() {
    let stdin = io::stdin();
    let mut scanner = Scanner::new(stdin.lock());
    let t=scanner.next_usize();
    for _ in 0..t 
    {
        let n=scanner.next_usize();
        let mut son=vec![Vec::<usize>::new();n+1];
        let mut fa=vec![0;n+1];
        let mut a=vec![0;n+1];
        let mut b=vec![0;n+1];
        for i in 1..n
        {
            let p=scanner.next_usize();
            let la=scanner.next_usize();
            let lb=scanner.next_usize();
            son[p].push(i+1);
            fa[i+1]=p;
            a[i+1]=la;
            b[i+1]=lb;
        }
        let mut sum=Vec::<usize>::new();
        let mut ans=vec![0;n+1];
        dfs(1,&son,&mut sum,&mut ans,0,&a,&b);
        for i in 2..n+1
        {
            print!("{} ",ans[i]);
        }
        println!("\n");
    }
}
