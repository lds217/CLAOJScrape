// Template //
#include <bits/stdc++.h>
#define FOR(i, a, b) for(ll i=a, _b=b; i<=_b; i++)
#define FORD(i, a, b) for(ll i=a, _b=b; i>=_b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define MASK(i) (1LL<<(i))
#define BIT(x, i) (((x)>>(i))&1)
#define task "SUADUONG"
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;
static struct FastInput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t chars_read = 0;
  size_t buf_pos = 0;
  FILE *in = stdin;
  char cur = 0;

  inline char get_char() {
    if (buf_pos >= chars_read) {
      chars_read = fread(buf, 1, BUF_SIZE, in);
      buf_pos = 0;
      buf[0] = (chars_read == 0 ? -1 : buf[0]);
    }
    return cur = buf[buf_pos++];
  }

  inline void tie(int) {}

  inline explicit operator bool() {
    return cur != -1;
  }

  inline static bool is_blank(char c) {
    return c <= ' ';
  }

  inline bool skip_blanks() {
    while (is_blank(cur) && cur != -1) {
      get_char();
    }
    return cur != -1;
  }

  inline FastInput& operator>>(char& c) {
    skip_blanks();
    c = cur;
    return *this;
  }

  inline FastInput& operator>>(string& s) {
    if (skip_blanks()) {
      s.clear();
      do {
        s += cur;
      } while (!is_blank(get_char()));
    }
    return *this;
  }

  template <typename T>
  inline FastInput& read_integer(T& n) {
    // unsafe, doesn't check that characters are actually digits
    n = 0;
    if (skip_blanks()) {
      int sign = +1;
      if (cur == '-') {
        sign = -1;
        get_char();
      }
      do {
        n += n + (n << 3) + cur - '0';
      } while (!is_blank(get_char()));
      n *= sign;
    }
    return *this;
  }

  template <typename T>
  inline typename enable_if<is_integral<T>::value, FastInput&>::type operator>>(T& n) {
    return read_integer(n);
  }

  #if !defined(_WIN32) || defined(_WIN64)
  inline FastInput& operator>>(__int128& n) {
    return read_integer(n);
  }
  #endif

  template <typename T>
  inline typename enable_if<is_floating_point<T>::value, FastInput&>::type operator>>(T& n) {
    // not sure if really fast, for compatibility only
    n = 0;
    if (skip_blanks()) {
      string s;
      (*this) >> s;
      sscanf(s.c_str(), "%lf", &n);
    }
    return *this;
  }
} fast_input;

#define cin fast_input

static struct FastOutput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t buf_pos = 0;
  static constexpr int TMP_SIZE = 1 << 20;
  char tmp[TMP_SIZE];
  FILE *out = stdout;

  inline void put_char(char c) {
    buf[buf_pos++] = c;
    if (buf_pos == BUF_SIZE) {
      fwrite(buf, 1, buf_pos, out);
      buf_pos = 0;
    }
  }

  ~FastOutput() {
    fwrite(buf, 1, buf_pos, out);
  }

  inline FastOutput& operator<<(char c) {
    put_char(c);
    return *this;
  }

  inline FastOutput& operator<<(const char* s) {
    while (*s) {
      put_char(*s++);
    }
    return *this;
  }

  inline FastOutput& operator<<(const string& s) {
    for (int i = 0; i < (int) s.size(); i++) {
      put_char(s[i]);
    }
    return *this;
  }

  template <typename T>
  inline char* integer_to_string(T n) {
    // beware of TMP_SIZE
    char* p = tmp + TMP_SIZE - 1;
    if (n == 0) {
      *--p = '0';
    } else {
      bool is_negative = false;
      if (n < 0) {
        is_negative = true;
        n = -n;
      }
      while (n > 0) {
        *--p = (char) ('0' + n % 10);
        n /= 10;
      }
      if (is_negative) {
        *--p = '-';
      }
    }
    return p;
  }

  template <typename T>
  inline typename enable_if<is_integral<T>::value, char*>::type stringify(T n) {
    return integer_to_string(n);
  }

  #if !defined(_WIN32) || defined(_WIN64)
  inline char* stringify(__int128 n) {
    return integer_to_string(n);
  }
  #endif

  template <typename T>
  inline typename enable_if<is_floating_point<T>::value, char*>::type stringify(T n) {
    sprintf(tmp, "%.17f", n);
    return tmp;
  }

  template <typename T>
  inline FastOutput& operator<<(const T& n) {
    auto p = stringify(n);
    for (; *p != 0; p++) {
      put_char(*p);
    }
    return *this;
  }
} fast_output;

#define cout fast_output



const int maxn=2*1e5+2;

bool maximize(int &A, int B)
{
    return A<B ? A=B, true : false;
}

bool minimize(int &A, int B)
{
    return A>B ? A=B, true : false;
}


//main

int n,q;
string s[maxn];
const int lg=22;
int cnt[3000002][26],lca[3000002][lg],id[maxn],fid[maxn],h[3000002],node[maxn];

int timer=0;
void add(int i)
{
	int par=0;
	for(char c: s[id[i]])
	{
		if(!cnt[par][c-'a'])
		{
			cnt[par][c-'a']=++timer;
			lca[timer][0]=par;
			h[timer]=h[par]+1;
			FOR(i,1,21)
				lca[timer][i]=lca[lca[timer][i-1]][i-1];
		}
		par=cnt[par][c-'a'];
	}
	node[i]=par;
}

void input()
{
	cin>>n>>q;
	FOR(i,1,n)
		cin>>s[i],id[i]=i;
}

int LCA(int a,int b)
{
	if(a==b)	return h[a];
	if(h[a]<h[b])	swap(a,b);
	int d=h[a]-h[b];
	while(d>0)
	{
		int i=log2(d);
		a=lca[a][i];
		d-=MASK(i);
	}

	if(a==b)	return h[a];
	FORD(i,21,0)
	{
		if(lca[b][i]!=lca[a][i])
			b=lca[b][i],a=lca[a][i];
	}
	return 	h[lca[a][0]];
}


void lds_go_goooo()
{
	sort(id+1,id+1+n,[&](int a,int b)
	{
		return s[a]<s[b];
	});
	
	FOR(i,1,n)
		fid[id[i]]=i,add(i);
	
	while(q--)
	{
		int n;
		cin>>n;
		int maxx=-1e9;
		int minn=1e9;
		FOR(i,1,n)
		{
			int tmp;
			cin>>tmp;
			minimize(minn,fid[tmp]);
			maximize(maxx,fid[tmp]);
		}
		cout<<LCA(node[maxx],node[minn])<<"\n";
	}
}

int main()
{
 	ios_base::sync_with_stdio(false);
   // cin.tie(0);
  //  cout.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
    }
    return 0;
}
