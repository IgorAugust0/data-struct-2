import java.util.Arrays;

public class TSP{

    private int[][] graph;
    private int[] path;
    private int[] bestPath;
    private int bestCost;
    private int n;

    public TSP(int[][] graph){
        this.graph = graph;
        this.n = graph.length;
        this.path = new int[n];
        this.bestPath = new int[n];
        this.bestCost = Integer.MAX_VALUE;
    }

    public void solve(){
        for(int i = 0; i < n; i++){
            path[0] = i;
            solve(1);
        }
    }

    private void solve(int pos){
        if(pos == n){
            int cost = cost(path);
            if(cost < bestCost){
                bestCost = cost;
                System.arraycopy(path, 0, bestPath, 0, n);
            }
        }else{
            for(int i = 0; i < n; i++){
                if(!contains(path, i, pos)){
                    path[pos] = i;
                    solve(pos + 1);
                }
            }
        }
    }

    private boolean contains(int[] path, int city, int pos){
        for(int i = 0; i < pos; i++){
            if(path[i] == city){
                return true;
            }
        }
        return false;
    }

    private int cost(int[] path){
        int cost = 0;
        for(int i = 0; i < n - 1; i++){
            cost += graph[path[i]][path[i + 1]];
        }
        cost += graph[path[n - 1]][path[0]];
        return cost;
    }

    public int[] getBestPath(){
        return bestPath;
    }

    public int getBestCost(){
        return bestCost;
    }

    public String getBestPermutation(){
        return Arrays.toString(bestPath);
    }

    public int getBestDistance(){
        return bestCost;
    }

    
}