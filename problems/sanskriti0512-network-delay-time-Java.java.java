//https://leetcode.com/problems/network-delay-time/
// GRAPH 
class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        Graph g=new Graph(N);
        for(int i=0;i<times.length;i++){
            int u=times[i][0]-1;
            int v=times[i][1]-1;
            int w=times[i][2];
            g.addEdge(u,v,w);
        }
        K--;
        boolean visited[]=new boolean[N];
         int d[]=new int[N];
        for(int i=0;i<N;i++)
            d[i]=Integer.MAX_VALUE;
        d[K]=0;
   g.dijkstra(visited,d);
        int k=Integer.MIN_VALUE;
        for(int i=0;i<N;i++)
            k=Math.max(k,d[i]);
        if(k==Integer.MAX_VALUE)
            return -1;
        return k;
        
    }
}
class Graph{
    int  n;
    ArrayList<Edge> adj[];
    public Graph(int v){
        n=v;
        adj=new ArrayList[n];
        for(int i=0;i<n;i++){
            adj[i]=new ArrayList<>();
        }
    }
    public void addEdge(int u,int v,int w){
        adj[u].add(new Edge(v,w));
    }
    public int minDistanceVertex(boolean visited[],int []d){
        int min=Integer.MAX_VALUE,mini=-2;
        for(int i=0;i<n;i++){
        //    System.out.println(d[i]+" ");
            if(!visited[i] && d[i]<=min){
                min=d[i];mini=i;
            }
        }return mini;
    }
    public void dijkstra(boolean visited[],int []d){
        //System.out.println(s);
     for(int j=0;j<n-1;j++){
        int  mini=minDistanceVertex(visited,d);
        // System.out.println(mini+"**"+adj[mini].size());
         visited[mini]=true;
          for(int i=0;i<adj[mini].size();i++){
              Edge child=adj[mini].get(i);
            //   System.out.println(mini+"->"+child.des);
         if(!visited[child.des] && d[mini]!=Integer.MAX_VALUE  && d[child.des]>child.w+d[mini]){
             d[child.des]=child.w+d[mini];
         }
          }
         
     }   
    }
}
class Edge{
    int des;
    int w;
    public Edge(int x,int y){
        des=x;
        w=y;
    }
}