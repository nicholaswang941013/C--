#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

// 計算平均值
double average(const vector<double> & data){
    // 如果資料集為空，返回0
    if(data.empty()){
        return 0.0;
    }
    
    double sum = 0.0;
    // 遍歷資料集，計算總和
    for(const auto & num : data){
        sum += num;
    }
    
    // 計算平均值
    return sum / data.size();
}

// 計算標準差
double sigma(const vector<double> & data){
    // 如果資料集為空，返回0
    if(data.empty()){
        return 0.0;
    }
    
    // 先計算平均值
    double mean = average(data);
    double variation = 0.0;

    // 計算每個數據與平均值的差異的平方和
    for (const auto & num : data){
        double deviation = num - mean;
        variation += (deviation * deviation);
    }
    
    // 計算標準差
    return sqrt(variation / data.size());
}

int main()
{
    int numData;
    vector<double> data;
    
    // 提示使用者輸入資料數量
    cout << "How many data: ";
    // 檢查輸入是否為正整數
    while (!(cin >> numData) || numData <= 0) {
        cout << "Please enter a positive integer: ";
        // 清除錯誤狀態並忽略當前輸入
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    // 輸入資料
    for (int i = 0; i < numData; ++i) {
        double value;
        cout << "Please enter " << i+1 << " data: ";
        // 檢查輸入是否為數字
        while (!(cin >> value)) {
            cout << "Invalid input. Please enter a number: ";
            // 清除錯誤狀態並忽略當前輸入
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        data.push_back(value);
    }
    
    // 設定輸出格式為小數點後三位
    cout << fixed << setprecision(3);
    
    // 輸出平均值和標準差
    cout << "Average: " << average(data) << endl;
    cout << "Sigma: " << sigma(data) << endl;
    
    // 等待使用者按下任意鍵
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
    return 0;
}