class Solution {
    public int minMaxDifference(int num) {
        String nums=Integer.toString(num);
        String a=nums;
        String b=nums;
        char targetMax =' ';
        for(char c:nums.toCharArray()) 
        {
            if(c!='9')
            {
                targetMax=c;
                break;
            }
        }
        if(targetMax!=' ')
        {
            a=nums.replace(targetMax,'9');
        }
        char targetMin= nums.charAt(0);
        b = nums.replace(targetMin,'0');
        int x=0,y=0;
        x= Integer.parseInt(a);
        y=Integer.parseInt(b);
        return x-y;

       

        
    }
}