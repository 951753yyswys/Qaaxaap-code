use std::io::{self, BufRead, StdinLock};
use std::{i64, str};
#[rustfmt::skip]#[allow(unused)] struct Scanner<'a> {stdin: StdinLock<'a>,buf: Vec<u8>,pos: usize,}
#[rustfmt::skip]#[allow(unused)]impl<'a> Scanner<'a> {pub fn new(stdin: StdinLock<'a>)->Self {Self {stdin,buf:Vec::new(),pos: 0,}}   
    pub fn rdi64(&mut self)->i64{self.sksp();let st=self.pos;while self.pos<self.buf.len(){let bt=self.buf[self.pos];
        if bt.is_ascii_digit()||(self.pos==st&&(bt==b'-'||bt==b'+')){self.pos+=1;}else {break;}}
        if self.pos==st{panic!("缺少数字");}let num_str=unsafe{str::from_utf8_unchecked(&self.buf[st..self.pos])};num_str.parse().unwrap()}
    pub fn rdf64(&mut self)->f64{self.sksp();let st=self.pos;while self.pos<self.buf.len(){let bt=self.buf[self.pos];
        if bt.is_ascii_digit()||bt==b'.'||bt==b'e'||bt==b'E'||bt==b'+'||bt==b'-'||(self.pos==st&&(bt==b'-'||bt==b'+')){self.pos+=1;}
        else {break;}}let num_str=unsafe{str::from_utf8_unchecked(&self.buf[st..self.pos])};num_str.parse().unwrap()}
    pub fn rdstring(&mut self)->String{self.sksp();let st=self.pos;while self.pos<self.buf.len()&&!self.buf[self.pos].is_ascii_whitespace(){self.pos+=1;}
        let word=unsafe{str::from_utf8_unchecked(&self.buf[st..self.pos])};word.to_string()}
    pub fn rdchar(&mut self)->char{self.ensure_buf(1);let bt=self.buf[self.pos];self.pos+=1;bt as char}
    fn sksp(&mut self){self.ensure_buf(1);while self.pos<self.buf.len()&&self.buf[self.pos].is_ascii_whitespace(){self.pos+=1;}
        if self.pos>=self.buf.len(){self.buf.clear();self.stdin.read_until(b'\n',&mut self.buf).unwrap();self.pos=0;self.sksp();}}
    fn ensure_buf(&mut self,n:usize){while self.buf.len()-self.pos<n{
        let mut temp=Vec::new();self.stdin.read_until(b'\n',&mut temp).unwrap();self.buf.extend(temp);}}
    pub fn peek_char(&mut self)->Option<char>{self.sksp();if self.pos<self.buf.len(){Some(self.buf[self.pos] as char)}else{None}}
    pub fn has_next(&mut self)->bool{self.sksp();self.pos<self.buf.len()}}
#[rustfmt::skip]#[allow(unused)]pub fn scanner()->Scanner<'static>{let stdin=io::stdin();Scanner::new(stdin.lock())}
#[allow(unused)]
fn main() {
    let stdin = io::stdin();
    let mut sc = Scanner::new(stdin.lock());
}
