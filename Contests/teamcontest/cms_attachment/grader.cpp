#include "Mahjong.h"

namespace {
  void _wa(string s) {
    cout << "Wrong_answer: " << s << endl;
    exit(0);
  }
  void _ac(string s) {
    cout << "Accepted: " << s << endl;
    exit(0);
  }
  const char GREEN = 'M';
  const char YELLOW = 'P';
  const char GRAY = 'N';
  const int GUESS_LIMIT = 53 * 2000 + 1;

  vector<string> hidden_hand;
  int current_guess = 0;
  bool success_guess = false;

  void ensuref(bool f, string msg) {
    if (!f) _wa(msg);
  }

  int c_index(char c) {
    if (c == 'm') return 0;
    else if (c == 'p') return 1;
    else if (c == 's') return 2;
    else return 3;
  }

  bool cmp_for_cards(string a, string b) {
    if (a[1] == b[1]) {
      return a[0] < b[0];
    }
    return c_index(a[1]) < c_index(b[1]);
  }

  void check_sorted(vector<string> cards) {
    vector<string> cards2 = cards;
    sort(cards2.begin(), cards2.begin() + 13, cmp_for_cards);
    ensuref(cards == cards2, "cards not sorted");
  }

  void check_4_cards(vector<string> cards) {
    map<string, int> mp;
    for (string s : cards) {
      mp[s] += 1;
    }
    for (pair<string, int> p : mp) {
      ensuref(p.second <= 4, "tile " + p.first + " too much (you give " + to_string(p.second) + " tiles)");
    }
  }

  void format_check(vector<string> cards) {
    ensuref((int)cards.size() == 14, "card number not correct");
    for (int i = 0; i < 14; ++i) {
      ensuref((int)cards[i].size() == 2, "string size not correct on card number " + to_string(i + 1) + "(1-base)");
      if ('1' <= cards[i][0] && cards[i][0] <= '9') {
        if (cards[i][1] == 'm' || cards[i][1] == 'p' || cards[i][1] == 's' || cards[i][1] == 'z') {
          if (cards[i][1] == 'z') {
            if (cards[i][0] == '8' || cards[i][1] == '9') {
              ensuref(false, "card " + to_string(i) + ": " + cards[i] + " is not a mahjong");
            }
          }
        }
        else {
          ensuref(false, "card " + to_string(i) + ": " + cards[i] + " is not a mahjong");
        }
      }
      else {
        ensuref(false, "card " + to_string(i) + ": " + cards[i] + " is not a mahjong");
      }
    }
    check_sorted(cards);
    check_4_cards(cards);
  }

  vector<int> cards_string_to_int(vector<string> &cards) {
    vector<int> cnt(34, 0);
    for (string s : cards) {
      if (s[1] == 'm') cnt[s[0] - '1']++;
      else if (s[1] == 'p') cnt[s[0] - '1' + 9]++;
      else if (s[1] == 's') cnt[s[0] - '1' + 18]++;
      else if (s[1] == 'z') cnt[s[0] - '1' + 27]++;
    }
    return cnt;
  }

  bool kokushi(vector<int> &cards_int) {
    vector<int> tars = {0, 8, 9, 17, 18, 26, 27, 28, 29, 30, 31, 32, 33};
    for (int i : tars) {
      if (cards_int[i] == 0) return false;
    }
    return true;
  }

  bool seven_pair(vector<int> &cards_int) {
    for (int i = 0; i < 34; ++i) {
      if (cards_int[i] != 0 && cards_int[i] != 2) return false;
    }
    return true;
  }

  bool check_straight(string s1, string s2, string s3) {
    if (s1[1] == 'z' || s2[1] == 'z' || s3[1] == 'z') return false;
    if (s1[1] != s2[1]) return false;
    if (s1[1] != s3[1]) return false;
    if (s2[1] != s3[1]) return false;
    if (s1[0] + 1 != s2[0]) return false;
    if (s2[0] + 1 != s3[0]) return false;
    return true;
  }

  bool visited[1 << 14];

  bool DP(vector<string> cards, int mask) {
    if (mask == 0) return true;
    if (visited[mask]) return false;
    visited[mask] = true;
    vector<int> v;
    for (int i = 0; i < 14; ++i) {
      if (((1 << i) & mask) != 0) {
        v.push_back(i);
      }
    }
    int n = (int)v.size();
    if (n == 2) { // terminal case
      return cards[v[0]] == cards[v[1]];
    }
    for (int i = 0; i < n - 2; ++i) {
      if (cards[v[i]] == cards[v[i + 1]] && cards[v[i + 1]] == cards[v[i + 2]]) {
        int newmask = mask ^ (1 << v[i]) ^ (1 << v[i + 1]) ^ (1 << v[i + 2]);
        if (DP(cards, newmask)) {
          return true;
        }
      }
    }
    for (int i = 0, j = 0, k = 0; i < n; ++i) {
      while (j < n && cards[v[i]] == cards[v[j]]) {
        ++j;
      }
      if (j == n) {
        break;
      }
      while (k < n && (cards[v[i]] == cards[v[k]] || cards[v[j]] == cards[v[k]])) {
        ++k;
      }
      if (j == n || k == n) {
        break;
      }
      if (cards[v[i]] == cards[v[j]] || cards[v[j]] == cards[v[k]] || cards[v[i]] == cards[v[k]]) {
        break;
      }
      if (check_straight(cards[v[i]], cards[v[j]], cards[v[k]])) {
        int newmask = mask ^ (1 << v[i]) ^ (1 << v[j]) ^ (1 << v[k]);
        if (DP(cards, newmask)) {
          return true;
        }
      }
    }
    return false;
  }

  bool is_hupai(vector<string> cards) {
    vector<int> cards_int = cards_string_to_int(cards);
    if (kokushi(cards_int)) {
      return true;
    }
    if (seven_pair(cards_int)) {
      return true;
    }
    for (int i = 0; i < (1 << 14); ++i) {
      visited[i] = false;
    }
    sort(cards.begin(), cards.end(), cmp_for_cards);
    return DP(cards, (1 << 14) - 1);
  }

  string _check(vector<string> cards) {
    ++current_guess;
    ensuref(current_guess <= GUESS_LIMIT, "Guess more then " + to_string(GUESS_LIMIT) + " qqq");
    format_check(cards);
    ensuref(is_hupai(cards), "not a winning hand"); // ???
    string ret = "";
    for (int i = 0; i < 14; ++i) {
      ret.push_back(GRAY);
    }
    map<string, int> cnt;
    for (int i = 0; i < 14; ++i) {
      cnt[hidden_hand[i]]++;
    }
    int green_cnt = 0;
    for (int i = 0; i < 14; ++i) {
      if (cards[i] == hidden_hand[i]) {
        ret[i] = GREEN;
        cnt[hidden_hand[i]]--;
        green_cnt++;
      }
    }
    for (int i = 0; i < 14; ++i) {
      if (ret[i] == GRAY && cnt[cards[i]] >= 1) {
        cnt[cards[i]] -= 1;
        ret[i] = YELLOW;
      }
    }
    if (green_cnt == 14) {
      success_guess = true;
    }
    return ret;
  }

  string print_cards(vector<string> cards) {
    string ret = "";
    for (string card : cards) {
      ret += card + " ";
    }
    return ret;
  }

  int play_single_game(bool print_info) {
    hidden_hand.clear();
    current_guess = 0;
    success_guess = false;
    for (int i = 0; i < 14; ++i) {
      string s; cin >> s;
      hidden_hand.push_back(s);
    }
    play();
    ensuref(success_guess, "Failed to guess this hand: " + print_cards(hidden_hand));
    if (print_info) {
      cerr << "successfully guess cards " << print_cards(hidden_hand) << "in " << current_guess << " tries." << endl;
    }
    return current_guess;
  }

  void play_game(bool print_info = false) {
    int total_guess = 0;
    int T; cin >> T;
    for (int i = 0; i < T; ++i) {
      int _ = play_single_game(print_info);
      total_guess += _;
    }
    _ac("Successfully guess all hands!! average is " + to_string(total_guess * 1.0 / T));
  }
}

string check(vector<string> cards) {
  return _check(cards);
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  play_game();
}
