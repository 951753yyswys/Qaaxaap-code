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
    let mut sc=Scanner::new(stdin.lock());
    const MOD:i64=1000000007;
    let q=sc.readi64();
    for _ in 0..q {
        let s:Vec<char>=sc.readstring().chars().collect();
        let t:Vec<char>=sc.readstring().chars().collect();
        let n=s.len();
        let m=t.len();
        let mut st=Vec::<usize>::new();
        if n<m {
            println!("0 1");
            continue;
        }
        for i in 0..=n-m {
            let mut flag=true;
            for j in 0..m {
                if s[i+j]!=t[j] {
                    flag=false;
                }
            }
            if flag {
                st.push(i);
            }
        }
        let mut ed=vec![false;n];
        for i in st {
            ed[i+m-1]=true;
        }
        let mut dp=vec![vec![vec![0i64;2usize];n+1];n+1];
        dp[0][0][0]=1i64;
        for i in 1..=n {
            for j in 0..=n {
                if j>0 && ed[i-1] {
                    dp[i][j][1]=(dp[i-m][j-1][0]+dp[i-m][j-1][1])%MOD;
                }   
                if ed[i-1] {
                    for k in i-m+1..=i-1 {
                        dp[i][j][0]=(dp[i][j][0]+dp[k][j][1])%MOD;
                    }
                }
                else {
                    dp[i][j][0]=(dp[i-1][j][1]+dp[i-1][j][0])%MOD;
                }
            }
        }
        let mut flag=true;
        for i in 0..=n {
            if dp[n][i][1]+dp[n][i][0]>0 {
                println!("{} {}",i,(dp[n][i][1]+dp[n][i][0])%MOD);
                flag=false;
                break;
            }
        }
        if flag {
            println!("0 1");
        }
    }
}
