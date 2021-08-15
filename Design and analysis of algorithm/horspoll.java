import java.util.Scanner;
public class horspoll
{
    public static int size=500;
    public static int table[]=new int[size];

   public void shifttable(String str)
    { 
        char pat[]=str.toCharArray();
        int m=str.length();
        for(int i=0;i<size;i++)
        {
            table[i]=m;
        }
        for(int j=0;j<m;j++)
        {
            table[pat[j]]=m-1-j;
        }
         for(int i=91;i<127;i++)
        System.out.print(" "+table[i]);
    }
    public int find(String text,String pattern)
    {
        char p[]=pattern.toCharArray();
        char t[]=text.toCharArray();
int i,fi=0;
int m=pattern.length();
int n=text.length();
i=m-1;
while(i<n)
{
    int k=0;
    while(k<m && (p[m-1-k]==t[i-k]))
    {
        k++;
    }
if(k==m)
{
   fi=(i-m+1);
   return fi;
}
else
{
i=i+table[t[i]];
}
}
return -1;
}
 public static void main(String[] args)
  {
        Scanner sc=new Scanner(System.in);
        System.out.print("enter the text :");
        String text = sc.nextLine();
        System.out.print("enter the pattern :");
        String pattern=sc.next();
        text=text.toLowerCase();
        pattern=pattern.toLowerCase();
        int pos;
horspoll h=new horspoll();
h.shifttable(pattern);
pos=h.find(text, pattern);

if(pos==-1)
System.out.print("\npattern was not found");
else
System.out.print("\npattern was  found at position "+pos);
}


}

