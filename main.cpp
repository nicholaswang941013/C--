#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>   // 包含 pow 和 sqrt 函數的標頭檔(算次方和平方根)
#include <iomanip>  // 包含控制輸出格式的標頭檔

using namespace std;

// 計算平均值
double average(const vector<double> & data){
    double sum = 0.0;
    double num = 0.0;
    
    for(int y = 0; y < data.size(); y++){
        num = data[y];
        sum += num;
    }
    
    if(data.size() == 0){
        return 0.0;  // 如果資料集為空，返回0
    }
    
    return sum / data.size();
}

// 計算標準差
double sigma(const vector<double> & data){
    double deviation = 0.0;
    double variation = 0.0;

    for (int x = 0; x < data.size(); x++){
        deviation = data[x] - average(data);
        variation += (deviation*deviation);
    }
    
    if(data.size() == 0){
        return 0.0;  // 如果資料集為空，返回0
    }
    
    return sqrt(variation / data.size() );
}

int main()
{
    int numData;
    vector<double> data;
    
    // 提示使用者輸入資料數量
    cout << "How many data: ";
    cin >> numData;
    
    // 輸入資料
    for (int i = 0; i < numData; ++i) {
        float value;
        cout << "please enter " << i+1 << " data: ";
        cin >> value;
        data.push_back(value);
    }
    
    // 設定輸出格式為小數點後三位
    cout << fixed << setprecision(3);
    
    // 輸出平均值和標準差
    cout << "average: " << average(data) << endl;
    cout << "sigma: " << sigma(data) << endl;
    
    system("pause");
    return 0;
}
