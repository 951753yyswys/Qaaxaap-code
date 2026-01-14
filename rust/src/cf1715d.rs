use std::io::{self,BufRead,StdinLock};
use std::{i32,str};
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
    pub fn next_i32(&mut self)->i32 
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
fn min(a:i32,b:i32)->i32 
{
    if a<b {a} else {b}
}
fn max(a:i32,b:i32)->i32
{
    if a>b {a} else {b}
}
fn main() 
{
    let stdin=io::stdin();
    let mut scanner=Scanner::new(stdin.lock());
    let n=scanner.next_i32();
    let q=scanner.next_i32();
    //let mut ans=vec![true as bool;n as usize+1];
    //let mut edge=vec![Vec::<i32>::new();n as usize+1];
    let mut qsi=vec![0;q as usize];
    let mut qsj=vec![0;q as usize];
    let mut qsx=vec![0;q as usize];
    let mut out=vec![0;n as usize+1];
    for i in 0..q 
    {
        let i=i as usize;
        qsi[i]=scanner.next_i32();
        qsj[i]=scanner.next_i32();
        qsx[i]=scanner.next_i32();
        /*for k in 0..31 
        {
            if (x>>k)&1==0 
            {
                ans[k][i as usize]=false;
                ans[k][j as usize]=false;
            }
            else
            {
                edge[k][i as usize].push(j);
                if i==j {continue;}
                edge[k][j as usize].push(i);
            }
        }*/
    }
   /* for i in 1..n+1
    {
        let mut res=0;
        for k in 0..31 
        {
            if ans[k][i as usize] 
            {
                let mut flag=false;
                for &to in &edge[k][i as usize] 
                {
                    if ans[k][to as usize]==false||to==i 
                    {
                        flag=true;
                        break;
                    }
                }
                if flag 
                {
                    ans[k][i as usize]=true;
                    res|=1<<k;
                }
                else {ans[k][i as usize]=false;}
            }
        }
        print!("{} ",res)
     } */  
    for k in 0..31 
    {
        let mut ans=vec![true as bool;n as usize+1];
        let mut edge=vec![Vec::<i32>::new();n as usize+1];
        for i in 0..q 
        {
            let i=i as usize;
            if (qsx[i]>>k)&1==0 
            {
                ans[qsi[i] as usize]=false;
                ans[qsj[i] as usize]=false;
            }
            else
            {
                edge[qsi[i] as usize].push(qsj[i]);
                if qsi[i]==qsj[i] {continue;}
                edge[qsj[i] as usize].push(qsi[i]);
            }
        }
        for i in 1..n+1 
        {
            if ans[i as usize] 
            {
                let mut flag=false;
                for &to in &edge[i as usize] 
                {
                    if ans[to as usize]==false||to==i 
                    {
                        flag=true;
                        break;
                    }
                }
                if flag 
                {
                    ans[i as usize]=true;
                    out[i as usize]|=1<<k;
                }
                else {ans[i as usize]=false;}
            }
        }
    }
    for i in 1..n+1 {print!("{} ",out[i as usize]);}
}
