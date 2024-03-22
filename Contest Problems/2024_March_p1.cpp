#include <bits/stdc++.h>
#define int long long

using namespace std;

bool evaluatesTo(vector<int> sentence, int start, int end) {
  int curSum;
  bool containsOrOperator = false;
  bool containsTrueValue = false;
  bool containsFalseValue = false;
  vector<int> andValues(sentence.size());

  if (end - start == 1) {
    if (end == sentence.size())
      return sentence[end - 1];
    else
      return sentence[0];
  } else if (start == end) {
    return sentence[start];
  }

  for (int i = start + 1; i < end; i += 2) {
    if (sentence[i]) {
      curSum = sentence[i - 1] * sentence[i + 1];
      andValues[i] = curSum;
      if (curSum) containsTrueValue = true;
    } else {
      containsOrOperator = true;
    }
  }

  if (containsOrOperator && containsTrueValue)
    return true;
  else if (!containsOrOperator && containsFalseValue)
    return false;

  for (int i = start + 1; i < end; i += 2) {
    if (!sentence[i] && (andValues[i - 2] || andValues[i + 2])) return true;
  }

  return false;
}

string evaluate(bool first, bool second, bool prevEval, bool nextEval,
                bool target) {
  if (target) {
    if ((!first || !second) || (first && prevEval) || (second && nextEval)) {
      return "Y";
    } else {
      return "N";
    }
  } else {
    if ((first || second) || (!first && !prevEval) || (!second && !nextEval)) {
      return "Y";
    } else {
      return "N";
    }
  }
}

string evaluateOneSide(bool isAnd, bool prevEval, bool nextEval, bool target,
                       bool dir) {
  if (dir) {
    if ((target && prevEval) || (!target && isAnd) ||
        (!target && !isAnd && !prevEval)) {
      return "Y";
    } else {
      return "N";
    }
  } else {
    if ((target && nextEval) || (!target && isAnd) ||
        (!target && !isAnd && !nextEval)) {
      return "Y";
    } else {
      return "N";
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string temp;
  int N, Q;
  cin >> N >> Q;
  vector<int> sentence;

  for (int i = 0; i < N; i++) {
    cin >> temp;

    if (i % 2 == 0) {
      if (temp == "true")
        sentence.push_back(1);
      else
        sentence.push_back(0);
    } else {
      if (temp == "and")
        sentence.push_back(1);
      else
        sentence.push_back(0);
    }
  }

  int L, R, target;

  for (int i = 0; i < Q; i++) {
    int prevEval, curEval, nextEval;
    cin >> L >> R >> temp;

    if (L == 1 && R == N) {
      cout << "Y";
      continue;
    }

    if (temp == "true")
      target = 1;
    else
      target = 0;

    L--;
    R--;
    prevEval = evaluatesTo(sentence, 0, L);
    nextEval = evaluatesTo(sentence, R, N - 1);

    if (L == 0) {
      cout << evaluateOneSide(sentence[R + 1], prevEval, nextEval, target, 0);
    } else if (R == N - 1) {
      cout << evaluateOneSide(sentence[L - 1], prevEval, nextEval, target, 1);
    } else {
      cout << evaluate(sentence[L - 1], sentence[R + 1], prevEval, nextEval,
                       target);
    }

    continue;
  }
}