use std::io::{self, BufRead, StdinLock};
use std::{i64, str};
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
    pub fn next_i64(&mut self) -> i64 {
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
            panic!("没有读取到数字");
        }
        let num_str = unsafe { str::from_utf8_unchecked(&self.buffer[start..self.pos]) };
        num_str.parse().unwrap()
    }
    pub fn next_f64(&mut self) -> f64 {
        self.skip_whitespace();
        let start = self.pos;
        while self.pos < self.buffer.len() {
            let byte = self.buffer[self.pos];
            if byte.is_ascii_digit()
                || byte == b'.'
                || byte == b'e'
                || byte == b'E'
                || byte == b'+'
                || byte == b'-'
                || (self.pos == start && (byte == b'-' || byte == b'+'))
            {
                self.pos += 1;
            } else {
                break;
            }
        }
        let num_str = unsafe { str::from_utf8_unchecked(&self.buffer[start..self.pos]) };
        num_str.parse().unwrap()
    }
    pub fn next_string(&mut self) -> String {
        self.skip_whitespace();
        let start = self.pos;
        while self.pos < self.buffer.len() && !self.buffer[self.pos].is_ascii_whitespace() {
            self.pos += 1;
        }
        let word = unsafe { str::from_utf8_unchecked(&self.buffer[start..self.pos]) };
        word.to_string()
    }
    pub fn next_char(&mut self) -> char {
        self.ensure_buffer(1);
        let byte = self.buffer[self.pos];
        self.pos += 1;
        byte as char
    }
    fn skip_whitespace(&mut self) {
        self.ensure_buffer(1);
        while self.pos < self.buffer.len() && self.buffer[self.pos].is_ascii_whitespace() {
            self.pos += 1;
        }
        if self.pos >= self.buffer.len() {
            self.buffer.clear();
            self.stdin.read_until(b'\n', &mut self.buffer).unwrap();
            self.pos = 0;
            self.skip_whitespace();
        }
    }
    fn ensure_buffer(&mut self, n: usize) {
        while self.buffer.len() - self.pos < n {
            let mut temp = Vec::new();
            self.stdin.read_until(b'\n', &mut temp).unwrap();
            self.buffer.extend(temp);
        }
    }
    pub fn peek_char(&mut self) -> Option<char> {
        self.skip_whitespace();
        if self.pos < self.buffer.len() {
            Some(self.buffer[self.pos] as char)
        } else {
            None
        }
    }
    pub fn has_next(&mut self) -> bool {
        self.skip_whitespace();
        self.pos < self.buffer.len()
    }
}
pub fn scanner() -> Scanner<'static> {
    let stdin = io::stdin();
    Scanner::new(stdin.lock())
}
fn letasc(c: char) -> usize {
    (c as u8 - b'a' + 1) as usize
}
fn asclet(num: u8) -> char {
    (b'a' + num - 1) as char
}
struct node {
    len: i64,
    st: Vec<i64>,  
}
fn dfs_iter(tr: &Vec<node>, root: usize, l0: i64, r0: i64) {
    let mut st: Vec<(usize, i64, i64, usize, i64)> = Vec::new();
    st.push((root, l0, r0, 0, 0));
    let mut out = String::with_capacity((r0 - l0 + 1) as usize);
    while let Some((mut u, mut l, mut r, mut i, mut pos)) = st.pop() {
        loop {
            if u <= 26 { break; }
            if tr[u].st.len() != 1 { break; }
            let v = tr[u].st[0] as usize;
            let seg_len = tr[u].len;            
            if l < 1 { l = 1; }
            if r > seg_len { r = seg_len; }
            u = v;
        }
        if u <= 26 {
            out.push(asclet(u as u8));
            continue;
        }
        while i < tr[u].st.len() {
            let v = tr[u].st[i] as usize;
            let start = pos + 1;
            let end = pos + tr[v].len.min(tr[u].len - pos); 
            if end >= l && start <= r {
                let child_l = if l > start { l - start + 1 } else { 1 };
                let child_r = if r < end { r - start + 1 } else { end - start + 1 };
                st.push((u, l, r, i + 1, end));
                st.push((v, child_l, child_r, 0, 0));
                break;
            }
            pos = end;
            i += 1;
            if pos >= r { break; }
        }
    }
    print!("{out}");
}
fn main() {
    let stdin = io::stdin();
    let mut scanner = Scanner::new(stdin.lock());
    let l = scanner.next_i64();
    let r = scanner.next_i64();
    let n = scanner.next_i64();
    let mut ed = vec![0; 27];  
    let mut cnt = 0 as usize;
    let mut tr = Vec::<node>::new();
    tr.push(node { len: 0, st: Vec::new() });
    for i in 1..=26 {
        cnt += 1;
        ed[i] = cnt;
        tr.push(node {
            len: 1,
            st: Vec::new(),  
        });
    }
    let mut a = vec!['a'; n as usize];
    let mut b = vec![String::new(); n as usize];
    for i in 0..n {
        let i = i as usize;
        a[i] = scanner.next_string().chars().next().unwrap();
        b[i] = scanner.next_string();
    }
    for i in (0..n).rev() {
        let i = i as usize;
        let c = letasc(a[i]);
        cnt += 1;
        let mut len = 0;
        let mut st = Vec::new();
        for ch in b[i].chars() {
            let to = letasc(ch);
            len += tr[ed[to]].len;
            st.push(ed[to] as i64);
            if len > r {
                len = r + 1;  
            }
        }
        tr.push(node { len, st });
        ed[c] = cnt;  
    }
    dfs_iter(&tr, ed[letasc('a')], l, r);

}
