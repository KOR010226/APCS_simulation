# APCS_simulation
#include <bits/stdc++.h>
using namespace std;
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    int Q;
    cin >> Q;
    char E;
    vector<string> v;
    char g[8][8];

    v.push_back("ABCDEFGH");
    v.push_back("IJKLMNOP");
    v.push_back("QRSTUVWX");
    v.push_back("YZabcdef");
    v.push_back("ghijklmn");
    v.push_back("opqrstuv");
    v.push_back("wxyz0123");
    v.push_back("456789+/");

    for(int i = 0 ;i < 8; i ++){
        string s = v[i];
        for(int j = 0 ;j < 8; j ++){
            g[i][j] = v[i][j];
        }
    }

    for(int i = 0 ;i < Q; i ++){
        char S;
        int t, N;
        cin >> S >> t >> N;
        int step = 1;
        
        for(int j = 0 ;j < N; j ++){
            char start = S;
            int x, y;
            bool jump = false;
            
            for(int k = 0; k < 8 ;k ++){
                for(int l = 0; l < 8 ;l ++){
                    if(g[k][l] == start){
                        x = l, y = k;
                        jump = true;
                        break;
                    }
                }
                if(jump) break;
            }
            
            for(int k = 1; k <= step; k ++){
                x += dx[t], y += dy[t];
                
                if(x > 7) x -= 8;
                else if(x < 0) x += 8;
                    
                if(y > 7) y -= 8;
                else if(y < 0) y += 8;
            }
            S = g[y][x];
            
            step ++;
            t += 1;
            
            if(t > 7) t -= 8;
        }
        E = S;
        cout << E << endl;
    }
    return 0;
}
