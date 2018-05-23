package APRIL18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Car {
	private final int velocity;
	private final boolean directionPositive;
	private final int length;
	private final long initialPosition;

	public Car(int velocity, boolean direction, int length, long initialPosition) {
		super();
		this.velocity = velocity;
		this.directionPositive = direction;
		this.length = length;
		this.initialPosition = initialPosition;
	}

	int getVelocity() {
		return velocity;
	}

	boolean isDirectionPositive() {
		return directionPositive;
	}

	int getLength() {
		return length;
	}

	long getInitialPosition() {
		return initialPosition;
	}

	private double calculateFrontPosition(double time) {
		double change = time * this.getVelocity();
		return this.isDirectionPositive() ? this.getInitialPosition() + change : this.getInitialPosition() - change;
	}

	private double calculateRearPosition(double time) {
		double front = calculateFrontPosition(time);
		if (this.isDirectionPositive())
			return front - this.getLength();
		else
			return front + this.getLength();
	}

	private boolean ge(double a, double b) {
		int x = Double.compare(a, b);
		return x == 1 || x == 0;
	}

	private boolean le(double a, double b) {
		int x = Double.compare(a, b);
		return x == -1 || x == 0;
	}

	private boolean isCarOverlappingWithZero(double time) {
		double front = calculateFrontPosition(time);
		double rear = calculateRearPosition(time);

		if ((ge(front, 0.0) && le(rear, 0.0)) || (le(front, 0.0) && ge(rear, 0.0)))
			return true;
		return false;
	}

	double calculateWaitingTime(double time, double chefTime) {

		if (isCarOverlappingWithZero(time) || isCarOverlappingWithZero(time + chefTime)) {
			double rear = Math.abs(calculateRearPosition(time));
			return rear / this.getVelocity();
		} else {
			return 0;
		}
	}

}

class HIGHWAYC {

	private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stz;

	private static int numberOfLanes, speedOfChef, widthOfLanes;

	public static void main(String[] args) throws NumberFormatException, IOException {
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			stz = new StringTokenizer(br.readLine());
			numberOfLanes = Integer.parseInt(stz.nextToken());
			speedOfChef = Integer.parseInt(stz.nextToken());
			widthOfLanes = Integer.parseInt(stz.nextToken());

			List<Integer> velocities, directions, positions, lengths;
			velocities = getListOfIntegers(numberOfLanes);
			directions = getListOfIntegers(numberOfLanes);
			positions = getListOfIntegers(numberOfLanes);
			lengths = getListOfIntegers(numberOfLanes);

			List<Car> cars = new ArrayList<>();
			for (int i = 0; i < numberOfLanes; i++) {
				cars.add(new Car(velocities.get(i), directions.get(i) == 1, lengths.get(i), positions.get(i)));
			}

			solve(cars);

		}
	}

	private static void solve(List<Car> cars) {
		double chefTime = (double) widthOfLanes / speedOfChef;
		double time = 0.0;
		for (int i = 0; i < cars.size(); i++) {
			double waitingTime = cars.get(i).calculateWaitingTime(time, chefTime);
			time += waitingTime + chefTime;
		}
		System.out.println(time);
	}

	// private static long getPositionOfCar(Car car, int time) {
	// long change = (long) time * car.getVelocity();
	// return car.isDirectionPositive() ? car.getInitialPosition() + change :
	// car.getInitialPosition() - change;
	// }

	private static List<Integer> getListOfIntegers(int n) throws IOException {
		List<Integer> result = new ArrayList<>();
		stz = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++)
			result.add(Integer.parseInt(stz.nextToken()));
		return result;
	}
}
