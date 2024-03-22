#define f first
#define s second
#define pb push_back
#define mp make_pair
#define int long long
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define sort(x) sort(all(x))
#define sortReverse(x) reverse(sort(x))
#define maxElement(x) *max_element(all(x))
#define minElement(x) *min_element(all(x))
#define insert(i, x, value) (x).emplace((x).begin() + (i), value)
#define delete(i, x) (x).erase((x).begin() + (i))
#define deleteRange(a, b, x) (x).erase((x).begin() + (a), (x).begin() + ((b) + 1))
#define count(target, x) count(all(x), target)

#define deb1(name, i, x) cout << name + i + ": " + x << endl;
#define deb2(name, i, a, b) cout << name + i + ": " + a + " " + b << endl;

#define intMax INT_MAX
#define intMin INT_MIN
#define PI 3.1415926