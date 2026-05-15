#include <iostream>
#include <vector>

void q1(int count, int n){
    if(count>n){
        return;
    }
    std::cout<<count<<std::endl;
    q1(count+1, n);
}

void q2(int n){
    if(n<1){
        return;
    }
    std::cout<<n<<std::endl;
    q2(n-1);
}

int q3(int n, int total){
    if(n<1){
        return total;
    }

    total+=n;
    return q3(n-1, total);
}

int q7(int n, int count){
    if(n==0){
        return count;
    }

    return q7(n/10, count+1);
}

int q8(int n, int sum){
    if(n==0){
        return sum;
    }

    sum+=(n%10);
    return q8(n/10, sum);
}

int q9(int n, int product){
    if(n==0){
        return product;
    }

    product*=(n%10);
    return q9(n/10, product);
}

int q10(int n, int sum){
    if(n==0){
        return sum;
    }

    sum*=10+(n%10);
    return q10(n/10, sum);
}

std::string decimalToBinary(int num){
    if(num==0){
        return "0";
    }

    std::string ans = "";

    while(num>0){
        int rem = num%2;
        ans += rem + '0';
        num/=2;

        std::cout<<"rem: "<<rem<<std::endl;
        std::cout<<"ans: "<<ans<<std::endl;
        std::cout<<"num: "<<num<<std::endl;
    }

    std::reverse(ans.begin(), ans.end());
    return ans;
}

std::vector<int> separateDigits(std::vector<int> &nums){
    int start = nums.size() - 1;
    int position = nums.size();
    for (int i = start; i >= 0; i--){
        int num = nums[i];
        std::cout<<"current num: "<<num<<std::endl;
        while (num != 0){
            int rem = num % 10;
            std::cout<<"rem: "<<rem<<std::endl;
            nums.at(position) = rem;
            num = num / 10;
            std::cout<<"num: "<<num<<std::endl;
            std::cout<<std::endl;
        }
    }

    return nums;
}

int main(){
    std::vector<int> v = {13,25,83,77};
    separateDigits(v);

    return 0;
}