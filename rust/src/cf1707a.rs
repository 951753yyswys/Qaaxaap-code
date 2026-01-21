use std::fs::read_link;
use std::io::{self,BufRead,StdinLock};
use std::{i64,str};
pub struct Scanner<'a> {stdin: StdinLock<'a>,buf: Vec<u8>,pos: usize,}
impl<'a> Scanner<'a> {pub fn new(stdin: StdinLock<'a>)->Self {Self {stdin,buf:Vec::new(),pos: 0,}}   
    pub fn readi64(&mut self)->i64{self.sksp();let st=self.pos;while self.pos<self.buf.len(){let bt=self.buf[self.pos];
        if bt.is_ascii_digit()||(self.pos==st&&(bt==b'-'||bt==b'+')){self.pos+=1;}else {break;}}
        if self.pos==st{panic!("缺少数字");}let num_str=unsafe{str::from_utf8_unchecked(&self.buf[st..self.pos])};num_str.parse().unwrap()}
    pub fn readf64(&mut self)->f64{self.sksp();let st=self.pos;while self.pos<self.buf.len(){let bt=self.buf[self.pos];
        if bt.is_ascii_digit()||bt==b'.'||bt==b'e'||bt==b'E'||bt==b'+'||bt==b'-'||(self.pos==st&&(bt==b'-'||bt==b'+')){self.pos+=1;}
        else {break;}}let num_str=unsafe{str::from_utf8_unchecked(&self.buf[st..self.pos])};num_str.parse().unwrap()}
    pub fn readstring(&mut self)->String{self.sksp();let st=self.pos;while self.pos<self.buf.len()&&!self.buf[self.pos].is_ascii_whitespace(){self.pos+=1;}
        let word=unsafe{str::from_utf8_unchecked(&self.buf[st..self.pos])};word.to_string()}
    pub fn readchar(&mut self)->char{self.ensure_buf(1);let bt=self.buf[self.pos];self.pos+=1;bt as char}
    fn sksp(&mut self){self.ensure_buf(1);while self.pos<self.buf.len()&&self.buf[self.pos].is_ascii_whitespace(){self.pos+=1;}
        if self.pos>=self.buf.len(){self.buf.clear();self.stdin.read_until(b'\n',&mut self.buf).unwrap();self.pos=0;self.sksp();}}
    fn ensure_buf(&mut self,n:usize){while self.buf.len()-self.pos<n{
        let mut temp=Vec::new();self.stdin.read_until(b'\n',&mut temp).unwrap();self.buf.extend(temp);}}
    pub fn peek_char(&mut self)->Option<char>{self.sksp();if self.pos<self.buf.len(){Some(self.buf[self.pos] as char)}else{None}}
    pub fn has_next(&mut self)->bool{self.sksp();self.pos<self.buf.len()}}
pub fn scanner()->Scanner<'static>{let stdin=io::stdin();Scanner::new(stdin.lock())}
fn main() {
    let stdin=io::stdin();
    let mut scanner=Scanner::new(stdin.lock());
    let t=scanner.readi64();
    for _ in 0..t {
        let n=scanner.readi64();
        let q=scanner.readi64();
        let mut a=vec![0i64;n as usize+1];
        let mut man=vec![0i64;n as usize+1];
        for i in 1..=n as usize {
            a[i]=scanner.readi64();
        }
        let mut ans=0i64;
        let mut iq=0i64;
        for i in (1..=n as usize).rev() {
            if iq>=a[i] {
                ans+=1;
                man[i]=1;
            }
            else {
                if iq<q {
                    iq+=1;
                    ans+=1;
                    man[i]=1;
                }
            }
        }
        for i in 1..=n as usize {
            print!("{}",man[i]);
        }
        println!("");
    }
}
