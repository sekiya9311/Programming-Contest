
// https://beta.atcoder.jp/contests/future-contest-2019-qual/submissions/3581362

#include <bits/stdc++.h>

using namespace std;

// タイマー,時間計測
// basis msec
// 1[sec] == 1000[msec]
class timer {
private:
  std::chrono::system_clock::time_point start;
  const long long LIMIT;
  bool is_start = false;

public:
  timer() : LIMIT(-1) {}
  timer(long long limit) : LIMIT(limit) {}

  void start_measure() {
    this->start = std::chrono::system_clock::now();
    this->is_start = true;
  }

  long long get_elapse_msec() const {
    if (!this->is_start) {
      throw std::runtime_error("Not start measure");
    }
    auto pass = std::chrono::system_clock::now() - this->start;
    return std::chrono::duration_cast<std::chrono::milliseconds>(pass).count();
  }

  long long get_remaining_msec() const {
    if (this->LIMIT == -1) {
      throw std::runtime_error("Not defined LIMIT");
    }
    return LIMIT - this->get_elapse_msec();
  }
};
timer tim(3000);

// xor_shift,ランダム
class xor_shift {
private:
  uint32_t x = 123456789;
  uint32_t y = 362436069;
  uint32_t z = 521288629;
  uint32_t w;

public:
  xor_shift(uint32_t seed = 0) : w(seed ? seed : 88675123) {
    this->random_loop();
  }
  void random_loop() {
    int loop_num = this->next() % 100;
    while (loop_num--)
      this->next();
  }
  uint32_t next(bool heavy_ok = false) {
    if (heavy_ok)
      this->random_loop();
    uint32_t t = this->x ^ (this->x << 11);
    this->x = this->y;
    this->y = this->z;
    this->z = this->w;
    return this->w = (this->w ^ (this->w >> 19)) ^ (t ^ (t >> 8));
  }
  uint64_t nextl(bool heavy_ok = false) {
    return ((((uint64_t)this->next(heavy_ok)) << 32) | this->next(heavy_ok));
  }
  uint32_t operator()(bool heavy_ok = false) { return this->next(heavy_ok); }
};
std::random_device rnd;
std::mt19937 mt(rnd());
xor_shift xrnd(mt());

inline string next() {
  static char buf[333];
  scanf("%s", buf);
  return buf;
}

enum class order {
  go = 1,
  left = 2,
  right = 4,
};
enum class direction {
  up = 1,
  down = 4,
  left = 2,
  right = 8,
};

int N;
int M;
int L;
string S[500];
string T[29], T_ans[29];
inline void init_map() {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      if (i == 0 || i + 1 == M || j == 0 || j + 1 == M) {
        T[i][j] = '#';
      } else {
        T[i][j] = 'L';
      }
    }
  }
}
void init() {
  tim.start_measure();
  scanf("%d%d%d", &N, &M, &L);
  for (int i = 0; i < N; i++) {
    S[i] = next();
  }
  for (int i = 0; i < M; i++) {
    T[i] = string(M, '.');
  }
  init_map();
}
void out_put() {
  for (int i = 0; i < M; i++) {
    printf("%s\r\n", T_ans[i].c_str());
  }
}




inline order get_order(char o) {
  switch (o) {
    case 'S': {
      return order::go;
    }
    case 'L': {
      return order::left;
    }
    case 'R': {
      return order::right;
    }
  }
}

inline bool inside(int nh, int nw) {
  return 0 <= nh && nh < M && 0 <= nw && nw < M && T[nh][nw] != '#';
}
inline bool inside(const pair<int, int> &p) {
  return inside(p.first, p.second);
}
pair<int, int> next(int nh, int nw, direction dir) {
  switch (dir) {
    case direction::up: {
      if (inside(nh - 1, nw)) return make_pair(nh - 1, nw);
      else return make_pair(nh, nw);
    }
    case direction::down: {
      if (inside(nh + 1, nw)) return make_pair(nh + 1, nw);
      else return make_pair(nh, nw);
    }
    case direction::right: {
      if (inside(nh, nw + 1)) return make_pair(nh, nw + 1);
      else return make_pair(nh, nw);
    }
    case direction::left: {
      if (inside(nh, nw - 1)) return make_pair(nh, nw - 1);
      else return make_pair(nh, nw);
    }
  }
}

void simu(int &now_h, int &now_w, direction &dir, order o) {
  
  const int loop = T[now_h][now_w] == 'D' ? 2 : T[now_h][now_w] == 'T' ? 3 : 1;
  
  if (o == order::left && T[now_h][now_w] == 'R') o = order::right;
  else if (o == order::right && T[now_h][now_w] == 'L') o = order::left;

  switch (o) {
    case order::go: {
      for (int i = 0; i < loop; i++) {
        tie(now_h, now_w) = next(now_h, now_w, dir);
      }
      break;
    }
    case order::left: {
      for (int i = 0; i < loop; i++) {
        if (dir == direction::right) dir = direction::up;
        else dir = (direction)((int)dir << 1);
      }
      break;
    }
    case order::right: {
      for (int i = 0; i < loop; i++) {
        if (dir == direction::up) dir = direction::right;
        else dir = (direction)((int)dir >> 1);
      }
      break;
    }
  }
}

int calc() {
  static int for_calc[29][29];
  memset(for_calc, 0, sizeof(for_calc));
  for (int i = 0; i < N; i++) {
    int now_h = M / 2, now_w = M / 2;
    direction now_dir = direction::up;
    for (auto o : S[i]) {
      simu(now_h, now_w, now_dir, get_order(o));
    }
    for_calc[now_h][now_w]++;
  }
  int ret = 0;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      ret += for_calc[i][j] == 1 ? 10 : for_calc[i][j] == 2 ? 3 : for_calc[i][j] == 3 ? 1 : 0;
    }
  }
  return ret;
}

void make_map() {
  init_map();
  for (int i = 1; i < M - 1; i++) {
    for (int j = 1; j < M - 1; j++) {
      char &c = T[i][j];
      if ((i == 1 || i == M - 2) && (j == 1 || j == M - 2)) {
        c = 'D';
      }
      int r = xrnd() % 20;
      if (false) c = '.';
      else if (r == 17) c = 'L';
      else if (r == 23) c = 'R';
    }
  }
}

priority_queue<pair<int, pair<int, int>>> pq;
int idx = -1;
string seq = "R.";
pair<int, int> st;
void make_map2() {
  idx = (idx + 1) % seq.size();
  if (idx == 0) {
    st = pq.top().second;
    pq.pop();
  }
  for (int i = 0; i < M; i++) {
    T[i] = T_ans[i];
  }
  T[st.first][st.second] = seq[idx];
}

bool debug = 0;
void solve() {
  int ma = 0, cnt = 0;
  while (tim.get_remaining_msec() > 2500) {
    cnt++;
    make_map();
    const int tmp = calc();
    if (ma < tmp) {
      ma = tmp;
      for (int i = 0; i < M; i++) {
        T_ans[i] = T[i];
      }
    }
    if (debug) cerr << "tmp: " << tmp << endl;
  }
  for (int i = 1; i < M - 1; i++) {
    for (int j = 1; j < M - 1; j++) {
      pq.emplace(abs(i - M / 2) + abs(j - M / 2), make_pair(i, j));
    }
  }
  while (tim.get_remaining_msec() > 20) {
    cnt++;
    make_map2();
    const int tmp = calc();
    if (ma < tmp) {
      ma = tmp;
      for (int i = 0; i < M; i++) {
        T_ans[i] = T[i];
      }
    }
    if (debug) cerr << "tmp: " << tmp << endl;
  }
  cerr << "ma: " << ma << endl;
  cerr << "cnt: " << cnt << endl;
}

int main() {
  init();
  solve();
  out_put();
}
