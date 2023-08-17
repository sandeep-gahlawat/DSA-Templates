class Solution {
    public int reverse(int number) {
        int reversed = 0;
        while (number != 0) {
            int digit = number % 10;
            reversed = reversed * 10 + digit;
            number /= 10;
        }
        return reversed;
    }
    public boolean sumOfNumberAndReverse(int num) {
        if(num == 0) return true;
        for (int i = 1; i <num; i++) {
            if (i + reverse(i) == num) return true;
        }
        return false;
    }
    public int is_special(string[] input,int input2)
    {
        int count = 0;
        int n = input.length;
        for(int i = 0;i<n;i++)
        {
            if(sumOfNumberAndReverse(Integer.parseInt(input[i])))
            {
                count++;
            }
        }
        return count;
    }
    public static void main(String args[]){  
//Declaring String variable  
string [] input1 = {"22","121"};

System.out.println(is_special(input1));//300, because 200+100, here + is a binary plus operator  
}
}
