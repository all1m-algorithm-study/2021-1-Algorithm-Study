package alim;

import java.util.ArrayList;
import java.util.Scanner;
 
public class boj2606_subln516 {
    static ArrayList<Integer>[] list;
    static boolean[] visit;
    static int N;
    static int M;   
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
         
         N = sc.nextInt();
         M = sc.nextInt();
         
        list = new ArrayList[N+1];
        visit = new boolean[N+1];
         
        for(int i=0; i<N+1; i++) list[i] = new ArrayList<>();
         
        for(int i=0; i<M; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            list[u].add(v);
            list[v].add(u);
        }
         
         
        dfs(1);
 
         
        int ans = 0;
        for(boolean f : visit){
            if(f == true) ans++;
        }
        System.out.println(ans-1);
         
    }
     
     
    private static void dfs(int u) {
        visit[u] = true;
         
        for(int v : list[u]){
            if(visit[v] == false) dfs(v);
        }
    }
 
}