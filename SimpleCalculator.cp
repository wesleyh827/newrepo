/*Project: Simple calculater using stack
 *
 *This calculator can deal with expressions containing open ( and closing parentheses ),
 *the plus + or minus sign -, non-negative integers and empty spaces.
 *
 *Author: Wesley Yu-Wei Huang
 *Date: 3/17/2021
 *School: Jianguo High School
 */
#include<iostream>
#include<stack>
using namespace std;
class SimpleCalculator {
public:
    
    int compute(stack<int> number, stack<char> operators)
    {
        //compute value
        while (!operators.empty())
        {
            char op = operators.top();
            operators.pop();
            int a = number.top();
            number.pop();
            int b = number.top();
            number.pop();
            if (op == '+')
                number.push(a+b);
            else if (op == '-')
                number.push(a-b);
        }
        return number.top();
    }
    
    string removespace(string space)
    {
        string ss = "";
        for (int i=0;i<space.size();i++){
            if (space[i]!=' ')
                ss += space[i];
    }
        return ss;
    }
    
    int calculate(string s) {
        stack<int> num;
        stack<char> ops;
        
        s = removespace(s); //remove spaces
        
        int i=0;
        int n = -1;
        while (i<s.size()){
            //current position is a (part of) number
            if (s[i]>='0' && s[i]<='9')
            {
                if (n==-1){n = 0;}
                n = n * 10 + s[i]-'0';
                i++;
            }
            else{
                if (n != -1){
                    num.push(n); //push number to stack
                    n = -1; // set n to 0 for new number
                }// ) compute value inside parentheses
                
                if (s[i] == ')')//calculate the numbers before the right parenthesis
                {
                    stack<int> tmp_number;
                    stack<char> tmp_operator;
                    while (ops.top()!='('){
                        tmp_operator.push(ops.top());
                        ops.pop();
                        tmp_number.push(num.top());
                        num.pop();
                    }//calculate the expression before ')'
                    tmp_number.push(num.top());
                    num.pop();
                    
                    num.push(compute(tmp_number, tmp_operator));
                    ops.pop(); //pop ')' from stack
                }
                else {
                    ops.push(s[i]);
                }
                i++;
            }
        }
        
        if (n!=-1)
            num.push(n);
        
        stack<int> tmp_number;
        stack<char> tmp_operator;
        while (!ops.empty())// run the function when there's still operator in stack
        {
            tmp_operator.push(ops.top());
            ops.pop();
            tmp_number.push(num.top());
            num.pop();
        }
        tmp_number.push(num.top());
        num.pop();
        
        return compute(tmp_number, tmp_operator);
    }
};
/*
 *main:the program main function
 */
int main()
{
    SimpleCalculator calculate;
    string expression="(9-(3+5)+4)-(2+1)+3-1"; //make any expressions with +,-, and ()
    int answer = calculate.calculate(expression);
    cout<< "The expression is:" << expression << endl;
    cout<< "The answer to the expression is:" << answer << endl;
    return 0;
}
