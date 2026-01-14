use std::io::{self,BufRead,StdinLock};
use std::{i64,str};
pub struct Scanner<'a> {stdin: StdinLock<'a>,buffer: Vec<u8>,pos: usize,}
impl<'a> Scanner<'a> {
    pub fn new(stdin: StdinLock<'a>)->Self {Self {stdin,buffer:Vec::new(),pos: 0,}}   
    pub fn next_i64(&mut self)->i64 {
        self.skip_whitespace();let start=self.pos;while self.pos<self.buffer.len() {
        let byte=self.buffer[self.pos];if byte.is_ascii_digit()||(self.pos==start&&(byte==b'-'||byte==b'+')) {self.pos+=1;} else {break;}}
        if self.pos == start {panic!("没有读取到数字");}let num_str = unsafe { str::from_utf8_unchecked(&self.buffer[start..self.pos]) };
        num_str.parse().unwrap()}
    pub fn next_f64(&mut self)->f64 {
        self.skip_whitespace();let start=self.pos;while self.pos<self.buffer.len() {let byte=self.buffer[self.pos];
        if byte.is_ascii_digit()||byte==b'.'||byte==b'e'||byte==b'E'||byte==b'+'||byte==b'-'||(self.pos==start&&(byte==b'-'||byte==b'+')) {self.pos+=1;}
        else {break;}} let num_str=unsafe{str::from_utf8_unchecked(&self.buffer[start..self.pos])};num_str.parse().unwrap()}
    pub fn next_string(&mut self)->String {
        self.skip_whitespace(); let start=self.pos;while self.pos<self.buffer.len()&&!self.buffer[self.pos].is_ascii_whitespace() {self.pos+=1;}
        let word=unsafe{str::from_utf8_unchecked(&self.buffer[start..self.pos])};word.to_string()}
    pub fn next_char(&mut self)->char {self.ensure_buffer(1);let byte=self.buffer[self.pos];self.pos+=1;byte as char}
    fn skip_whitespace(&mut self) {
        self.ensure_buffer(1);while self.pos<self.buffer.len() && self.buffer[self.pos].is_ascii_whitespace() {self.pos+=1;}
        if self.pos>=self.buffer.len() {self.buffer.clear();self.stdin.read_until(b'\n',&mut self.buffer).unwrap();self.pos=0;self.skip_whitespace();}}
    fn ensure_buffer(&mut self,n:usize) {
        while self.buffer.len()-self.pos<n {
        let mut temp=Vec::new();self.stdin.read_until(b'\n',&mut temp).unwrap();self.buffer.extend(temp);}}
    pub fn peek_char(&mut self)->Option<char> {
        self.skip_whitespace();if self.pos<self.buffer.len() {Some(self.buffer[self.pos] as char)} else {None}}
    pub fn has_next(&mut self)->bool {self.skip_whitespace();self.pos<self.buffer.len()}
}
pub fn scanner()->Scanner<'static> {let stdin=io::stdin();Scanner::new(stdin.lock())}
fn main() 
{
    let stdin=io::stdin();
    let mut scanner=Scanner::new(stdin.lock());
}
