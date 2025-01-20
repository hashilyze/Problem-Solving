// 배열 순회
// 생성일: 2025-01-16

public class ArrayTravals {
	public static void main( String[] args ){
		int R = 3;   //행
		int C = 4;   //열
		int[][] arr = {
			{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12}
		};
		System.out.println("===행우선-정방향===");
		print1(R, C, arr);
		System.out.println();
		System.out.println("===행우선-역방향===");
		print2(R, C, arr);
		System.out.println();
		
		System.out.println("===열우선-정방향===");
		print3(R, C, arr);
		System.out.println();
		System.out.println("===열우선-역방향===");
		print4(R, C, arr);
		System.out.println();
		
		System.out.println("===지그재그-정방향===");
		print5(R, C, arr);
		System.out.println();
		System.out.println("===지그재그-역방향===");
		print6(R, C, arr);
		System.out.println();
	}
	
	// ===행우선-정방향===
	static void print1(int R, int C, int[][] arr) {
		StringBuilder sb = new StringBuilder();
		for(int r = 0; r < R; ++r) {
			for(int c = 0; c < C; ++c) {
				sb.append(arr[r][c] + " ");
			}
			sb.append('\n');
		}
		System.out.print(sb.toString());
	}
	// ===행우선-역방향===	
	static void print2(int R, int C, int[][] arr) {
		StringBuilder sb = new StringBuilder();
		for(int r = 0; r < R; ++r) {
			for(int c = 0; c < C; ++c) {
				sb.append(arr[R - r - 1][C - c - 1] + " ");
			}
			sb.append('\n');
		}
		System.out.print(sb.toString());
	}
	// ===열우선-정방향===	
	static void print3(int R, int C, int[][] arr) {
		StringBuilder sb = new StringBuilder();
		for(int c = 0; c < C; ++c) {
			for(int r = 0; r < R; ++r) {
				sb.append(arr[r][c] + " ");
			}
			sb.append('\n');
		}
		System.out.print(sb.toString());
	}
	// ===열우선-역방향===
	static void print4(int R, int C, int[][] arr) {
		StringBuilder sb = new StringBuilder();
		for(int c = 0; c < C; ++c) {
			for(int r = 0; r < R; ++r) {
				sb.append(arr[R - r - 1][C - c - 1] + " ");
			}
			sb.append('\n');
		}
		System.out.print(sb.toString());
	}
	// 지그재그-정방향	
	static void print5(int R, int C, int[][] arr) {
		StringBuilder sb = new StringBuilder();
		for(int r = 0; r < R; ++r) {
			for(int c = 0; c < C; ++c) {
				if(r % 2 == 0) sb.append(arr[r][c] + " "); 
				else sb.append(arr[r][C - c - 1] + " ");
			}
			sb.append('\n');
		}
		System.out.print(sb.toString());
	}
	// 지그재그-역방향
	static void print6(int R, int C, int[][] arr) {
		StringBuilder sb = new StringBuilder();
		for(int r = 0; r < R; ++r) {
			for(int c = 0; c < C; ++c) {
				if(r % 2 == 0) sb.append(arr[R - r - 1][C - c - 1] + " "); 
				else sb.append(arr[R - r - 1][c] + " ");
			}
			sb.append('\n');
		}
		System.out.print(sb.toString());
	}
}
