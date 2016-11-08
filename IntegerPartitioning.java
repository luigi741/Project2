/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package integerpartitioning;

import java.util.ArrayList;
import java.util.Arrays;

/**
 *
 * @author Brandon
 */
public class IntegerPartitioning {

    /**
     * @param args the command line arguments
     */
    static int[][] dp;
    static int count;
    
    public static void main(String[] args) {
        count = 0;
        // TODO code application logic here
        int[] test = {5,2,3,4,10};
        int t = 10;
        
        int sizeOfArray = test.length;
        dp = new int[sizeOfArray][sizeOfArray];
        for(int i = 0; i < sizeOfArray;i++)
        {
            for(int j = 0; j < sizeOfArray; j++)
            {
                dp[i][j] = Integer.MAX_VALUE;
                System.out.println(dp[i][j]);
            }
        }
        
//        for(int i = 0; i < test.length; i ++)
//        {
//            int sum = 0;
//            
//            
//            
//                for(int j = i; j < test.length; j++)
//                {
//                    sum += test[j];
//                    if(sum <= t)
//                    {
//                    int minimum = Integer.MAX_VALUE;
//                    if(i != 0)
//                    {
//                        for(int x = 0; x < test.length ; x++)
//                        {
//                            if(minimum > dp[x][i-1])
//                            {
//                                System.out.println("DP[" + x + "][" + j + "] = " + dp[x][j]);
//                                minimum = dp[x][i-1];
//                                
//                            }
//                        }
//                    }
//                    else
//                    {
//                        minimum = 0;
//                    }
//                    dp[i][j] = ((int) Math.pow(t-sum, 2)) + minimum;
//                }
//                    else
//            {
//                break;
//            }
//            }
//           
//        }
//        int trueMinimum = Integer.MAX_VALUE;
//        for(int i = 0; i < test.length; i++)
//        {
//            if(trueMinimum > dp[i][test.length-1])
//            {
//                trueMinimum = dp[i][test.length-1];
//                System.out.println(trueMinimum);
//            }
//        }
//        for(int i = 0; i < sizeOfArray;i++)
//        {
//            for(int j = 0; j < sizeOfArray; j++)
//            {
//                dp[i][j] = -1;
//            }
//        }
        
        int test2 = epRecursive(test, t, 0, sizeOfArray);
        System.out.println(test2);
        for(int i = 0; i < sizeOfArray;i++)
        {
            for(int j = 0; j < sizeOfArray; j++)
            {
                System.out.print(dp[i][j] + " ");
            }
            System.out.print("\n");
        }
        System.out.println("THE ARRAY WAS USED: " + count + " times!");

//        
//        for(int i = 0; i < sizeOfArray;i++)
//        {
//            for(int j = i; j < sizeOfArray; j++)
//            {
//                if(i == j)
//                {
//                    dp[i][j] = test[j];
//                }
//                else
//                {
//                    dp[i][j] = dp[i][j-1] + test[j];
//                }
//                if(dp[i][j] <= 10)
//                {
//                    System.out.println("dp[" + i + "][" + j + "]: " + dp[i][j] + "\n");
//                }
//            }
//        }
    }
    
    private static int epRecursive(int[] s, int t, int startingIndex, int sizeOfArray)
    {
        int minimum = Integer.MAX_VALUE;
        int next =0;
        int current = 0;
        int nextIndex =startingIndex;
        
        for(int i = 0; i < s.length; i++)
        {
            next += s[i];
            if(next <= t)
            {
                for(int x = startingIndex; x < sizeOfArray; x++)
                {
                    if(startingIndex < sizeOfArray)
                    {
                        if(minimum > dp[startingIndex][x])
                        {
                            minimum = dp[startingIndex][x];
                            System.out.println("MIN: " + minimum);

                        }
                        if(dp[startingIndex][x] == Integer.MAX_VALUE)
                        {
                            minimum = dp[startingIndex][x];
                            break;
                        }

                    }
                }
                if(minimum != Integer.MAX_VALUE)
                {
                    count++;
                    return minimum;
                }
        
                if(startingIndex < sizeOfArray)
                {
                    dp[startingIndex][nextIndex] = ((int) Math.pow(t - next, 2)) + epRecursive(Arrays.copyOfRange(s,i+1, s.length), t,nextIndex + 1, sizeOfArray);
                    System.out.println("DP[" + startingIndex + "]["+ nextIndex + "] = " + dp[startingIndex][nextIndex]);
                }
            }
            else
            {
                dp[startingIndex][nextIndex] = Integer.MAX_VALUE - 1;
            }

            nextIndex++;
        }
        System.out.println("S:");
        for(int i = 0; i < s.length; i++)
        {
            System.out.println(s[i]);
        }
        for(int i = 0; i < sizeOfArray; i++)
        {
            if(startingIndex < sizeOfArray)
            {
                if(minimum > dp[startingIndex][i])
                {
                    minimum = dp[startingIndex][i];
                    System.out.println("MIN: " + minimum);

                }
                
            }
        }
        if(minimum == Integer.MAX_VALUE)
        {
            minimum = 0;
        }
        return minimum;
    }
    
    public class Holder
    {
        public int numberOfPartitions;
        public ArrayList partitions;
        
        public Holder()
        {
            numberOfPartitions = 0;
        }
        
        public int getNumberOfPartitions()
        {
            return this.numberOfPartitions;
        }
        
        public void setNumberOfPartitions(int partitionsNUmbers)
        {
            this.numberOfPartitions = partitionsNUmbers;
        }
        
        public ArrayList getPartitions()
        {
            return this.partitions;
        }
        
        public void addToPartition(int a)
        {
            this.partitions.add(a);
        }
                
    }

}
