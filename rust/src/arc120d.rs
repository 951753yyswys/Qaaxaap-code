use std::io::{self,BufRead,StdinLock};
use std::{i64,str};
pub struct Scanner<'a> 
{
    stdin: StdinLock<'a>,
    buffer: Vec<u8>,
    pos: usize,
}
impl<'a> Scanner<'a> 
{
    pub fn new(stdin: StdinLock<'a>)->Self 
    {
        Self 
        {
            stdin,
            buffer:Vec::new(),
            pos: 0,
        }
    }   
    pub fn next_i64(&mut self)->i64 
    {
        self.skip_whitespace();   
        let start=self.pos;
        while self.pos<self.buffer.len() 
        {
            let byte=self.buffer[self.pos];
            if byte.is_ascii_digit()||(self.pos==start&&(byte==b'-'||byte==b'+')) {self.pos+=1;} 
            else {break;}
        }
        if self.pos == start {
            panic!("没有读取到数字");
        }
        let num_str = unsafe { str::from_utf8_unchecked(&self.buffer[start..self.pos]) };
        num_str.parse().unwrap()
    }
    pub fn next_f64(&mut self)->f64 
    {
        self.skip_whitespace();   
        let start=self.pos;
        while self.pos<self.buffer.len() 
        {
            let byte=self.buffer[self.pos];
            if byte.is_ascii_digit()||byte==b'.'||byte==b'e'||byte==b'E'||byte==b'+'||byte==b'-'||(self.pos==start&&(byte==b'-'||byte==b'+')) {self.pos+=1;} 
            else {break;}
        }
        let num_str=unsafe{str::from_utf8_unchecked(&self.buffer[start..self.pos])};
        num_str.parse().unwrap()
    }
    pub fn next_string(&mut self)->String 
    {
        self.skip_whitespace();   
        let start=self.pos;
        while self.pos<self.buffer.len()&&!self.buffer[self.pos].is_ascii_whitespace() {self.pos+=1;}
        let word=unsafe{str::from_utf8_unchecked(&self.buffer[start..self.pos])};
        word.to_string()
    }
    pub fn next_char(&mut self)->char 
    {
        self.ensure_buffer(1);   
        let byte=self.buffer[self.pos];
        self.pos+=1;
        byte as char
    }
    fn skip_whitespace(&mut self) 
    {
        self.ensure_buffer(1);   
        while self.pos<self.buffer.len() && self.buffer[self.pos].is_ascii_whitespace() {self.pos+=1;}
        if self.pos>=self.buffer.len() 
        {
            self.buffer.clear();
            self.stdin.read_until(b'\n',&mut self.buffer).unwrap();
            self.pos=0;
            self.skip_whitespace();  
        }
    }
    fn ensure_buffer(&mut self,n:usize) 
    {
        while self.buffer.len()-self.pos<n 
        {
            let mut temp=Vec::new();
            self.stdin.read_until(b'\n',&mut temp).unwrap();
            self.buffer.extend(temp);
        }
    }
    pub fn peek_char(&mut self)->Option<char> 
    {
        self.skip_whitespace();   
        if self.pos<self.buffer.len() {Some(self.buffer[self.pos] as char)} 
        else {None}
    }
    pub fn has_next(&mut self)->bool 
    {
        self.skip_whitespace();
        self.pos<self.buffer.len()
    }
}
pub fn scanner()->Scanner<'static> 
{
    let stdin=io::stdin();
    Scanner::new(stdin.lock())
}
fn main() 
{
    struct pair
    {
        first:i64,
        second:i64,
    }
    let stdin=io::stdin();
    let mut scanner=Scanner::new(stdin.lock());
    let n=scanner.next_i64() as usize;
    let mut a=Vec::new();
    let mut ans=vec!['!';2*n];
    for _ in 0..2*n 
    {a.push(scanner.next_i64());}    
    let mut sta=Vec::<pair>::new();
    let mut b=Vec::<pair>::new();
    let mut flg=vec![false;2*n];
    for i in 0..2*n 
    {
        b.push(pair{first:a[i],second:i as i64});
    }
    b.sort_by(|a, b| {
        if a.first != b.first {
            a.first.cmp(&b.first)
        } else {
            a.second.cmp(&b.second)
        }
    });
    for i in 0..n 
    {
        flg[b[i].second as usize]=true;
    }
    for i in 0..2*n
    {
        if sta.is_empty()||sta.last().unwrap().second==flg[i] as i64 
        {
            sta.push(pair{first:i as i64,second:flg[i] as i64});
        }
        else 
        {
            let p=sta.pop().unwrap();
            ans[p.first as usize]='(';
            ans[i as usize]=')';
        }
    }
    for i in 0..2*n 
    {
        print!("{}",ans[i]);
    }
}
