// 로봇 - 최적화
// 생성일: 2025-01-20

import java.io.*;
import java.util.*;

public class robot_optimized1 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	// Maker
	static final char SPCAE = 'S';
	static final char WALL = 'W';
	static final char ROBOT_A = 'A';
	static final char ROBOT_B = 'B';
	static final char ROBOT_C = 'C';
	
	// Delta
	static final int[][] d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	static final int DELTA_A_LIMIT = 1;
	static final int DELTA_B_LIMIT = 2;
	static final int DELTA_C_LIMIT = 4;
	
	static Deque<int[]> deqA = new ArrayDeque<>();
	static Deque<int[]> deqB = new ArrayDeque<>();
	static Deque<int[]> deqC = new ArrayDeque<>();
	
	public static void main(String[] args) throws IOException {
		int T = Integer.parseInt(br.readLine());
		for(int t = 1; t <= T; ++t) {
			// Input
			int N = Integer.parseInt(br.readLine());
			
			int[][] mat = new int[N][N];
			for(int y = 0; y < N; ++y) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(int x = 0; x < N; ++x) {
					mat[y][x] = st.nextToken().charAt(0);
					
					switch(mat[y][x]) {
					case ROBOT_A: deqA.add(new int[]{x, y}); break;
					case ROBOT_B: deqB.add(new int[]{x, y}); break;
					case ROBOT_C: deqC.add(new int[]{x, y}); break;
					}
				}
			}
			
			// Solution
			int ans = solution(N, mat);
			
			// Output
			bw.append("#" + t + " " + ans + "\n");
		}
		bw.flush();
	}
	
	static int solution(int N, int[][] mat) {
		int ans = 0;
		while(!deqA.isEmpty()) {
			int[] robot = deqA.poll();
			ans += getMovableSapces(robot,DELTA_A_LIMIT, d, N, mat);
		}
		while(!deqB.isEmpty()) {
			int[] robot = deqB.poll();
			ans += getMovableSapces(robot, DELTA_B_LIMIT, d, N, mat);
		}
		while(!deqC.isEmpty()) {
			int[] robot = deqC.poll();
			ans += getMovableSapces(robot, DELTA_C_LIMIT, d, N, mat);
		}
		return ans;
	}
	
	// 이동할 수 있는 셀인지 확인
	static boolean isMovalbe(int y, int x, int N, int[][] mat) {
		return 0 <= y && y < N && 0 <= x && x < N /* 격자 내 */ 
				&& mat[y][x] == SPCAE; /* 빈공간 */
	}
	
	static int getMovableSapces(int[] pos, int M, int[][] delta, int N, int[][] mat) {
		int ans = 0;
		for(int i = 0; i < M; ++i) {
			for(int d = 1; true; ++d) {
				int ny = pos[1] + delta[i][1] * d;
				int nx = pos[0] + delta[i][0] * d;
				
				if(!isMovalbe(ny, nx, N, mat)) break;
				
				++ans;
			}
		}
		return ans;
	}
}
