package APRIL18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

class CHEFWORK {
	static class Worker {
		public static final Worker DUMMY = new Worker(Integer.MAX_VALUE, -1);
		int cost, type;

		public Worker(int cost, int type) {
			this.cost = cost;
			this.type = type;
		}
	}

	private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stz;

	public static void main(String[] args) throws NumberFormatException, IOException {
		int n = Integer.parseInt(br.readLine());

		List<Integer> c = new ArrayList<>(n);
		stz = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++)
			c.add(Integer.parseInt(stz.nextToken()));

		List<Integer> type = new ArrayList<>(n);
		stz = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++)
			type.add(Integer.parseInt(stz.nextToken()));

		List<Worker> workers = new ArrayList<>(n);
		for (int i = 0; i < n; i++)
			workers.add(new Worker(c.get(i), type.get(i)));

		Comparator<Worker> workerComparator = new Comparator<Worker>() {

			@Override
			public int compare(Worker o1, Worker o2) {
				return o1.cost - o2.cost;
			}
		};
		int x = getMinByType(workers, workerComparator, 3);
		int y = getMinByType(workers, workerComparator, 1);
		int z = getMinByType(workers, workerComparator, 2);
		if (y != Integer.MAX_VALUE && z != Integer.MAX_VALUE)
			System.out.println(Integer.min(x, y + z));
		else
			System.out.println(x);
	}

	public static int getMinByType(List<Worker> workers, Comparator<Worker> workerComparator, int type) {
		return workers.stream().filter(w -> w.type == type).min(workerComparator).map(w -> w)
				.orElse(Worker.DUMMY).cost;
	}

}
