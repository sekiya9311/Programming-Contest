#ifdef int
#undef int
#endif
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <set>

namespace greed_tester {
using namespace std;

ifstream data("${Dependencies.testcase.GeneratedFileName}");

enum Color { RED, GREEN };
string color_string(string s, Color c){
#ifdef _MSC_VER
    return s;
#else
    switch(c){
        return s;
    case RED:
        return "\\e[31m\\e[1m" + s + "\\e[0m";
    case GREEN:
        return "\\e[32m\\e[1m" + s + "\\e[0m";
    default:
        return s;
    }
#endif
}

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

${<if HasArray}
template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}
${<end}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\\"" + t + "\\"";
}

${<if ReturnsArray}
template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < (int)ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}
${<end}

${<if Method.ReturnType.RealNumber}
bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }

${<if Method.ReturnType.Array}
bool double_vector_equal (const vector<double> &expected, const vector<double> &received) {
    if (expected.size() != received.size()) return false;
    int n = expected.size();
    for (int i = 0; i < n; ++i)
        if (!double_equal(expected[i], received[i])) return false;
    return true;
}
${<end}
${<end}

bool do_test(${Method.Params}, ${Method.ReturnType} __expected) {
    time_t startClock = clock();
    ${ClassName} *instance = new ${ClassName}();
    ${Method.ReturnType} __result = instance->${Method.Name}(${foreach Method.Params par , }${par.Name}${end});
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

${<if Method.ReturnType.RealNumber}
${<if Method.ReturnType.Array}
    if (double_vector_equal(__expected, __result)) {
${<else}
    if (double_equal(__expected, __result)) {
${<end}
${<else}
    if (__result == __expected) {
${<end}
        cout << color_string("PASSED!", GREEN) << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "Result   : " << color_string("FAILED!", RED)   << " (" << elapsed << " seconds)" << endl;
        cout << "Expected : " << to_string(__expected) << endl;
        cout << "Received : " << to_string(__result) << endl;
        return false;
    }
}

int run_test() {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
${<foreach Method.Params param}
${<if !param.Type.Array}
        ${param.Type.Primitive} ${param.Name};
${<else}
        vector<${param.Type.Primitive}> ${param.Name};
${<end}
        from_stream(${param.Name});
${<end}
        next_line();
${<if !Method.ReturnType.Array}
        ${Method.ReturnType.Primitive} __answer;
${<else}
        vector<${Method.ReturnType.Primitive}> __answer;
${<end}
        from_stream(__answer);

        cases++;

        cout << "===== Testcase #" << cases - 1 << " =====" << endl;
        if (do_test(${foreach Method.Params param , }${param.Name}${end}, __answer)) {
            passed++;
        }
    }
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
    int T = time(NULL) - ${CreateTime};
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << ${Problem.Score} * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}

}

int main() {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << "${Problem.Name} (${Problem.Score} Points)" << endl << endl;
    return greed_tester::run_test();
}
