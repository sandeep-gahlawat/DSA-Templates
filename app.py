def is_special(input1, input2):

    count = 0
    for( i=0; i < input2; i++):
    
        stringstream integer(input1[i])
        // next 3 lines converts string to integer
        int n = 0
        integer >> n

        for(int i=0
            i <= n/2
            i++)
        {
            int num = i

            int rev_num = 0
            // next 6 lines reverses no
            while(num > 0)
            {
                rev_num = rev_num*10 + num % 10
                num = num/10
            }
            int j = rev_num

            if((i+j) == n)
            {
                count++
                break
            }
        }
    }
    return count
}

int main()
{
    char * str[4] = {"1313", "5", "51", "33"}
    // creating string array of size n
    cout << is_special(str, 4)
    return 0
}
