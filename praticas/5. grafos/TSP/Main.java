import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter the number of cities: ");
            int numberOfCities = scanner.nextInt();

            int[][] distance = new int[numberOfCities][numberOfCities];

            for (int i = 0; i < numberOfCities; i++) {
                for (int j = 0; j < numberOfCities; j++) {
                    System.out.printf("Enter the distance from city %d to city %d: ", i, j);
                    distance[i][j] = scanner.nextInt();
                }
            }

            TSP tsp = new TSP(distance);
            tsp.solve();

            System.out.println("Shortest distance: " + tsp.getBestDistance());
            System.out.println("Best permutation: " + tsp.getBestPermutation());
        }
    }
}