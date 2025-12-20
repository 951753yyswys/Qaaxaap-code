// correct_interactive_judge.cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>
#include <iomanip>
#include <set>

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

class HiddenPermutationGame {
private:
    int n;
    vector<int> p;           // 隐藏排列，p[i] = 节点编号
    vector<set<int>> graph;  // 图的邻接表（节点编号从1开始）
    int query_count;
    int max_queries;
    bool terminated;

public:
    HiddenPermutationGame(int n, const vector<int>& permutation) 
        : n(n), p(permutation), query_count(0), max_queries(2 * n), terminated(false) {
        graph.resize(n + 1);  // 节点编号从1到n
    }
    
    // 类型1操作：添加边
    // 在节点 i 和节点 x-i 之间添加边，其中 1 ≤ i ≤ n 且 1 ≤ x-i ≤ n
    bool add_edges_for_x(int x) {
        if (terminated) return false;
        if (query_count >= max_queries) {
            terminated = true;
            return false;
        }
        if (x < 2 || x > 2 * n) {
            terminated = true;
            return false;
        }
        
        // 添加所有满足条件的边
        for (int i = 1; i <= n; i++) {
            int j = x - i;
            if (1 <= j && j <= n) {
                // 添加无向边
                graph[i].insert(j);
                graph[j].insert(i);
            }
        }
        
        query_count++;
        return true;
    }
    
    // 类型2操作：查询距离
    // 查询节点 p[i] 和节点 p[j] 之间的最短距离
    int query_shortest_path(int i, int j) {
        if (terminated) return -2;
        if (query_count >= max_queries) {
            terminated = true;
            return -2;
        }
        if (i < 1 || i > n || j < 1 || j > n) {
            terminated = true;
            return -2;
        }
        
        // 获取排列值对应的节点
        int node_u = p[i - 1];  // p[i] 是节点编号
        int node_v = p[j - 1];  // p[j] 是节点编号
        
        if (node_u == node_v) {
            query_count++;
            return 0;
        }
        
        // BFS寻找最短路径
        vector<int> dist(n + 1, -1);
        queue<int> q;
        dist[node_u] = 0;
        q.push(node_u);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : graph[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    if (v == node_v) {
                        query_count++;
                        return dist[v];
                    }
                    q.push(v);
                }
            }
        }
        
        query_count++;
        return -1;  // 不连通
    }
    
    bool check_guess(const vector<int>& guess1, const vector<int>& guess2) {
        if (terminated) return false;
        
        // 检查是否为有效排列
        if (!is_valid_permutation(guess1) || !is_valid_permutation(guess2)) {
            terminated = true;
            return false;
        }
        
        // 检查是否至少一个猜测正确
        bool correct = (guess1 == p) || (guess2 == p);
        terminated = true;
        return correct;
    }
    
    bool is_valid_permutation(const vector<int>& arr) {
        if (arr.size() != n) return false;
        vector<bool> seen(n + 1, false);
        for (int val : arr) {
            if (val < 1 || val > n || seen[val]) return false;
            seen[val] = true;
        }
        return true;
    }
    
    int get_query_count() const { return query_count; }
    bool is_over_limit() const { return query_count >= max_queries; }
    bool is_terminated() const { return terminated; }
    
    vector<int> get_permutation() const { return p; }
    
    // 调试：打印图
    void print_graph_debug() {
        cout << "当前图状态 (节点连接):" << endl;
        for (int i = 1; i <= n; i++) {
            cout << "节点 " << i << ": ";
            for (int neighbor : graph[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
    
    // 调试：打印排列
    void print_permutation_debug() {
        cout << "隐藏排列: ";
        for (int i = 0; i < n; i++) {
            cout << "p[" << (i+1) << "]=" << p[i] << " ";
        }
        cout << endl;
    }
};

class InteractiveJudge {
private:
    vector<pair<int, vector<int>>> test_cases;
    int current_case;
    HiddenPermutationGame* game;
    vector<string> log;
    bool show_interaction;
    bool color_output;
    
public:
    InteractiveJudge(bool show_interaction = true, bool color = true) 
        : current_case(0), game(nullptr), show_interaction(show_interaction), color_output(color) {
        srand(time(NULL));
    }
    
    void display_header() {
        if (color_output) {
            cout << BOLD << CYAN << "\n╔══════════════════════════════════════════════════╗" << RESET << endl;
            cout << BOLD << CYAN << "║       隐藏排列问题 - 正确交互评测器              ║" << RESET << endl;
            cout << BOLD << CYAN << "╚══════════════════════════════════════════════════╝" << RESET << endl;
        } else {
            cout << "\n=====================================================" << endl;
            cout << "       隐藏排列问题 - 正确交互评测器           " << endl;
            cout << "=====================================================" << endl;
        }
    }
    
    void read_test_cases_from_stdin() {
        cout << "\n" << (color_output ? YELLOW : "") << "输入测试用例" << (color_output ? RESET : "") << endl;
        cout << "══════════════════════════════════════════════════" << endl;
        
        cout << "测试用例数量 t (1 ≤ t ≤ 100): ";
        int t;
        cin >> t;
        
        for (int case_idx = 0; case_idx < t; case_idx++) {
            cout << "\n" << (color_output ? CYAN : "") << "测试用例 " << case_idx + 1 << (color_output ? RESET : "") << endl;
            cout << "n (2 ≤ n ≤ 1000): ";
            int n;
            cin >> n;
            
            cout << "隐藏排列 (" << n << "个互不相同的1~n的数字): ";
            vector<int> perm(n);
            for (int i = 0; i < n; i++) {
                cin >> perm[i];
            }
            
            test_cases.push_back({n, perm});
        }
    }
    
    void generate_random_test_cases(int t, int max_n) {
        test_cases.clear();
        cout << "\n" << (color_output ? YELLOW : "") << "生成随机测试用例" << (color_output ? RESET : "") << endl;
        cout << "══════════════════════════════════════════════════" << endl;
        
        for (int i = 0; i < t; i++) {
            int n = rand() % (max_n - 2 + 1) + 2;
            vector<int> perm(n);
            for (int j = 0; j < n; j++) {
                perm[j] = j + 1;
            }
            
            for (int j = n - 1; j > 0; j--) {
                int k = rand() % (j + 1);
                swap(perm[j], perm[k]);
            }
            
            test_cases.push_back({n, perm});
            
            if (color_output) {
                cout << GREEN << "✓ " << RESET << "测试用例 " << i + 1 << ": n = " << n 
                     << ", 排列 = ";
                for (int j = 0; j < min(n, 10); j++) {
                    cout << perm[j] << " ";
                }
                if (n > 10) cout << "...";
                cout << endl;
            } else {
                cout << "测试用例 " << i + 1 << ": n = " << n 
                     << ", 排列 = ";
                for (int j = 0; j < min(n, 10); j++) {
                    cout << perm[j] << " ";
                }
                if (n > 10) cout << "...";
                cout << endl;
            }
        }
    }
    
    void print_interaction(const string& role, const string& message, bool is_error = false) {
        if (color_output) {
            if (role == "选手") {
                cout << BOLD << BLUE << "【选手输出】" << RESET << " " << message << endl;
            } else if (role == "评测器") {
                if (is_error) {
                    cout << BOLD << RED << "【评测器返回】" << RESET << " " << message << endl;
                } else {
                    cout << BOLD << GREEN << "【评测器返回】" << RESET << " " << message << endl;
                }
            } else if (role == "信息") {
                cout << BOLD << YELLOW << "【信息】" << RESET << " " << message << endl;
            } else if (role == "错误") {
                cout << BOLD << RED << "【错误】" << RESET << " " << message << endl;
            } else if (role == "调试") {
                cout << BOLD << MAGENTA << "【调试】" << RESET << " " << message << endl;
            } else if (role == "图状态") {
                cout << BOLD << CYAN << "【图状态】" << RESET << " " << message << endl;
            }
        } else {
            cout << "【" << role << "】 " << message << endl;
        }
        
        log.push_back("【" + role + "】 " + message);
    }
    
    void run_judge(const string& solution_path) {
        if (test_cases.empty()) {
            print_interaction("错误", "没有测试用例！", true);
            return;
        }
        
        display_header();
        
        log.clear();
        print_interaction("信息", "开始评测解决方案: " + solution_path);
        
        string compiled_path = compile_solution(solution_path);
        if (compiled_path.empty()) {
            print_interaction("错误", "编译失败！", true);
            return;
        }
        
        int to_child[2];
        int from_child[2];
        
        if (pipe(to_child) == -1 || pipe(from_child) == -1) {
            print_interaction("错误", "管道创建失败", true);
            return;
        }
        
        pid_t pid = fork();
        if (pid == -1) {
            print_interaction("错误", "fork失败", true);
            return;
        }
        
        if (pid == 0) {
            close(to_child[1]);
            close(from_child[0]);
            
            dup2(to_child[0], STDIN_FILENO);
            dup2(from_child[1], STDOUT_FILENO);
            
            close(to_child[0]);
            close(from_child[1]);
            
            execl(compiled_path.c_str(), compiled_path.c_str(), NULL);
            
            cerr << "无法执行解决方案" << endl;
            exit(1);
        } else {
            close(to_child[0]);
            close(from_child[1]);
            
            fcntl(from_child[0], F_SETFL, O_NONBLOCK);
            
            string t_str = to_string(test_cases.size()) + "\n";
            write(to_child[1], t_str.c_str(), t_str.length());
            
            if (show_interaction) {
                print_interaction("评测器", "发送测试用例数量: " + to_string(test_cases.size()));
            }
            
            bool all_correct = true;
            int total_queries = 0;
            
            for (size_t i = 0; i < test_cases.size(); i++) {
                current_case = i + 1;
                auto& [n, perm] = test_cases[i];
                
                print_interaction("信息", 
                    "开始测试用例 " + to_string(current_case) + 
                    "/" + to_string(test_cases.size()) + 
                    " (n = " + to_string(n) + ")");
                
                if (show_interaction) {
                    print_interaction("调试", "隐藏排列: " + vector_to_string(perm));
                    
                    // 显示排列的详细信息
                    string perm_detail = "排列详情: ";
                    for (int j = 0; j < n; j++) {
                        perm_detail += "p[" + to_string(j+1) + "]=" + to_string(perm[j]) + " ";
                    }
                    print_interaction("调试", perm_detail);
                }
                
                game = new HiddenPermutationGame(n, perm);
                
                string n_str = to_string(n) + "\n";
                write(to_child[1], n_str.c_str(), n_str.length());
                
                if (show_interaction) {
                    print_interaction("评测器", "发送 n = " + to_string(n));
                }
                
                bool case_completed = false;
                int case_queries = 0;
                
                while (!game->is_terminated()) {
                    string query = read_from_pipe(from_child[0]);
                    if (query.empty()) {
                        int status;
                        if (waitpid(pid, &status, WNOHANG) == pid) {
                            print_interaction("错误", "解决方案意外终止", true);
                            all_correct = false;
                            case_completed = true;
                            break;
                        }
                        usleep(10000);
                        continue;
                    }
                    
                    if (show_interaction) {
                        print_interaction("选手", query);
                    }
                    case_queries++;
                    
                    istringstream iss(query);
                    string query_type;
                    iss >> query_type;
                    
                    if (query_type == "+") {
                        int x;
                        if (!(iss >> x)) {
                            write(to_child[1], "-2\n", 3);
                            print_interaction("评测器", "返回: -2 (无效查询)", true);
                            all_correct = false;
                            case_completed = true;
                            break;
                        }
                        
                        bool valid = game->add_edges_for_x(x);
                        string response = valid ? "1\n" : "-2\n";
                        write(to_child[1], response.c_str(), response.length());
                        
                        if (show_interaction) {
                            print_interaction("评测器", "返回: " + string(valid ? "1" : "-2"));
                        }
                        
                        if (!valid) {
                            print_interaction("错误", "查询无效或超过限制", true);
                            all_correct = false;
                            case_completed = true;
                            break;
                        }
                        
                    } else if (query_type == "?") {
                        int i, j;
                        if (!(iss >> i >> j)) {
                            write(to_child[1], "-2\n", 3);
                            print_interaction("评测器", "返回: -2 (无效查询)", true);
                            all_correct = false;
                            case_completed = true;
                            break;
                        }
                        
                        int result = game->query_shortest_path(i, j);
                        string response = to_string(result) + "\n";
                        write(to_child[1], response.c_str(), response.length());
                        
                        if (show_interaction) {
                            print_interaction("评测器", "返回: " + to_string(result));
                            
                            // 显示查询的详细信息
                            if (i >= 1 && i <= n && j >= 1 && j <= n) {
                                vector<int> p = game->get_permutation();
                                string debug_info = "查询详情: 查询节点 p[" + to_string(i) + "]=" + 
                                                   to_string(p[i-1]) + " 和 p[" + to_string(j) + "]=" + 
                                                   to_string(p[j-1]) + " 之间的距离";
                                print_interaction("调试", debug_info);
                            }
                        }
                        
                        if (result == -2) {
                            print_interaction("错误", "查询无效或超过限制", true);
                            all_correct = false;
                            case_completed = true;
                            break;
                        }
                        
                    } else if (query_type == "!") {
                        vector<int> guess1, guess2;
                        bool parse_error = false;
                        
                        // 读取第一个排列
                        for (int k = 0; k < n; k++) {
                            int val;
                            if (!(iss >> val)) {
                                parse_error = true;
                                break;
                            }
                            guess1.push_back(val);
                        }
                        
                        // 读取第二个排列
                        if (!parse_error) {
                            for (int k = 0; k < n; k++) {
                                int val;
                                if (!(iss >> val)) {
                                    parse_error = true;
                                    break;
                                }
                                guess2.push_back(val);
                            }
                        }
                        
                        if (parse_error) {
                            write(to_child[1], "-2\n", 3);
                            print_interaction("评测器", "返回: -2 (猜测格式错误)", true);
                            all_correct = false;
                            case_completed = true;
                            break;
                        }
                        
                        bool correct = game->check_guess(guess1, guess2);
                        string response = correct ? "1\n" : "-2\n";
                        write(to_child[1], response.c_str(), response.length());
                        
                        if (show_interaction) {
                            print_interaction("评测器", "返回: " + string(correct ? "1" : "-2"));
                            
                            if (correct) {
                                print_interaction("信息", 
                                    GREEN "✓ 猜测正确！" RESET 
                                    "查询次数: " + to_string(game->get_query_count()));
                            } else {
                                print_interaction("信息", 
                                    RED "✗ 猜测错误！" RESET 
                                    "查询次数: " + to_string(game->get_query_count()));
                                print_interaction("调试", 
                                    "猜测1: " + vector_to_string(guess1));
                                print_interaction("调试", 
                                    "猜测2: " + vector_to_string(guess2));
                                print_interaction("调试", 
                                    "正确答案: " + vector_to_string(perm));
                            }
                        }
                        
                        if (!correct) {
                            all_correct = false;
                        }
                        
                        case_completed = true;
                        break;
                        
                    } else {
                        write(to_child[1], "-2\n", 3);
                        print_interaction("评测器", "返回: -2 (未知查询类型)", true);
                        all_correct = false;
                        case_completed = true;
                        break;
                    }
                    
                    if (show_interaction) {
                        cout << endl;
                    }
                }
                
                total_queries += game->get_query_count();
                delete game;
                game = nullptr;
                
                if (!case_completed) {
                    print_interaction("错误", "测试用例未完成", true);
                    all_correct = false;
                }
                
                if (show_interaction && i < test_cases.size() - 1) {
                    cout << "\n" << string(60, '=') << "\n" << endl;
                }
            }
            
            close(to_child[1]);
            close(from_child[0]);
            
            int status;
            waitpid(pid, &status, 0);
            
            remove(compiled_path.c_str());
            
            display_final_result(all_correct, total_queries);
        }
    }
    
private:
    string compile_solution(const string& source_path) {
        print_interaction("信息", "编译解决方案: " + source_path);
        
        string compiled_path = "/tmp/solution_" + to_string(getpid());
        string cmd = "g++ -std=c++17 -O2 -o " + compiled_path + " " + source_path + " 2>&1";
        
        char buffer[1024];
        FILE* pipe = popen(cmd.c_str(), "r");
        if (!pipe) return "";
        
        string output;
        while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
            output += buffer;
        }
        
        int status = pclose(pipe);
        
        if (status != 0) {
            print_interaction("错误", "编译失败:", true);
            cout << output << endl;
            return "";
        } else if (!output.empty()) {
            print_interaction("信息", "编译警告:");
            cout << output << endl;
        } else {
            print_interaction("信息", GREEN "✓ 编译成功" RESET);
        }
        
        return compiled_path;
    }
    
    string read_from_pipe(int fd) {
        char buffer[1024];
        string result;
        
        while (true) {
            int n = read(fd, buffer, sizeof(buffer) - 1);
            if (n <= 0) break;
            
            buffer[n] = '\0';
            result += buffer;
            
            if (result.find('\n') != string::npos) {
                break;
            }
        }
        
        size_t pos = result.find('\n');
        if (pos != string::npos) {
            string line = result.substr(0, pos);
            if (!line.empty() && line.back() == '\r') {
                line.pop_back();
            }
            return line;
        }
        
        return "";
    }
    
    string vector_to_string(const vector<int>& vec) {
        stringstream ss;
        for (size_t i = 0; i < vec.size(); i++) {
            if (i > 0) ss << " ";
            ss << vec[i];
        }
        return ss.str();
    }
    
    void display_final_result(bool all_correct, int total_queries) {
        cout << "\n";
        cout << (color_output ? BOLD CYAN : "") 
             << "╔══════════════════════════════════════════════════╗" 
             << (color_output ? RESET : "") << endl;
        cout << (color_output ? BOLD CYAN : "") 
             << "║                评测结果总结                      ║" 
             << (color_output ? RESET : "") << endl;
        cout << (color_output ? BOLD CYAN : "") 
             << "╚══════════════════════════════════════════════════╝" 
             << (color_output ? RESET : "") << endl;
        
        cout << "\n测试用例数量: " << test_cases.size() << endl;
        cout << "总查询次数: " << total_queries << endl;
        cout << "平均查询次数: " << fixed << setprecision(1) 
             << (double)total_queries / test_cases.size() << endl;
        
        if (all_correct) {
            cout << "\n" << (color_output ? BOLD GREEN : "") 
                 << "✓ 恭喜！所有测试用例通过！" 
                 << (color_output ? RESET : "") << endl;
        } else {
            cout << "\n" << (color_output ? BOLD RED : "") 
                 << "✗ 抱歉！部分测试用例失败" 
                 << (color_output ? RESET : "") << endl;
            //cout << (color_output ? YELLOW : "") 
            //     << "提示：检查图构建是否正确，特别是 + n+1 和 + n+2 创建的链结构" 
            //     << (color_output ? RESET : "") << endl;
        }
    }
};

void print_usage(const char* prog_name) {
    cout << "隐藏排列问题 - 正确交互评测器\n" << endl;
    cout << "使用方法: " << prog_name << " [随机数据范围（可选）] <解决方案.cpp> [选项]\n" << endl;
    cout << "选项:" << endl;
    cout << "  --random t max_n     生成随机测试用例" << endl;
    cout << "  --no-color           禁用彩色输出" << endl;
    cout << "  --quiet              只显示最终结果，不显示详细交互" << endl;
    cout << "  --help               显示此帮助信息\n" << endl;
    cout << "示例:" << endl;
    cout << "  " << prog_name << " CF1815B.cpp              # 测试你的代码" << endl;
    cout << "  " << prog_name << " --random 5 10 sol.cpp    # 生成 5 个 n<=10 的测试点，并测试 sol.cpp" << endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2 || string(argv[1]) == "--help") {
        print_usage(argv[0]);
        return 0;
    }
    
    bool show_interaction = true;
    bool color_output = true;
    string solution_path;
    
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "--no-color") {
            color_output = false;
        } else if (arg == "--quiet") {
            show_interaction = false;
        } else if (arg[0] != '-') {
            solution_path = arg;
        }
    }
    
    if (solution_path.empty()) {
        cerr << "错误：请指定解决方案文件" << endl;
        print_usage(argv[0]);
        return 1;
    }
    
    InteractiveJudge judge(show_interaction, color_output);
    
    if (color_output) {
        cout << BOLD << "隐藏排列问题 - 正确交互评测器" << RESET << endl;
    } else {
        cout << "隐藏排列问题 - 正确交互评测器" << endl;
    }
    cout << "解决方案: " << solution_path << endl;
    cout << "说明: 已正确实现题目要求的交互逻辑" << endl;
    
    bool use_random = false;
    int random_t = 0, random_max_n = 0;
    
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "--random" && i + 2 < argc) {
            use_random = true;
            random_t = atoi(argv[i + 1]);
            random_max_n = atoi(argv[i + 2]);
            break;
        }
    }
    
    if (use_random) {
        judge.generate_random_test_cases(random_t, random_max_n);
    } else {
        judge.read_test_cases_from_stdin();
    }
    
    judge.run_judge(solution_path);
    
    return 0;
}
