#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

// �p�⥭����
double average(const vector<double> & data){
    // �p�G��ƶ����šA��^0
    if(data.empty()){
        return 0.0;
    }
    
    double sum = 0.0;
    // �M����ƶ��A�p���`�M
    for(const auto & num : data){
        sum += num;
    }
    
    // �p�⥭����
    return sum / data.size();
}

// �p��зǮt
double sigma(const vector<double> & data){
    // �p�G��ƶ����šA��^0
    if(data.empty()){
        return 0.0;
    }
    
    // ���p�⥭����
    double mean = average(data);
    double variation = 0.0;

    // �p��C�ӼƾڻP�����Ȫ��t��������M
    for (const auto & num : data){
        double deviation = num - mean;
        variation += (deviation * deviation);
    }
    
    // �p��зǮt
    return sqrt(variation / data.size());
}

int main()
{
    int numData;
    vector<double> data;
    
    // ���ܨϥΪ̿�J��Ƽƶq
    cout << "How many data: ";
    // �ˬd��J�O�_�������
    while (!(cin >> numData) || numData <= 0) {
        cout << "Please enter a positive integer: ";
        // �M�����~���A�é�����e��J
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    // ��J���
    for (int i = 0; i < numData; ++i) {
        double value;
        cout << "Please enter " << i+1 << " data: ";
        // �ˬd��J�O�_���Ʀr
        while (!(cin >> value)) {
            cout << "Invalid input. Please enter a number: ";
            // �M�����~���A�é�����e��J
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        data.push_back(value);
    }
    
    // �]�w��X�榡���p���I��T��
    cout << fixed << setprecision(3);
    
    // ��X�����ȩM�зǮt
    cout << "Average: " << average(data) << endl;
    cout << "Sigma: " << sigma(data) << endl;
    
    // ���ݨϥΪ̫��U���N��
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
    return 0;
}