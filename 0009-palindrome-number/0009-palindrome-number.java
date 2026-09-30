class Solution {
    public boolean isPalindrome(int originalNum) {
        if(originalNum<0){
            return false;
        }
        int reverseNum=0;
        int temp= originalNum;

        while(originalNum != 0){
            int lastDigit= originalNum%10;
            originalNum= originalNum/10;

            reverseNum = reverseNum*10 + lastDigit;
        }

        return reverseNum == temp;      
    }
}