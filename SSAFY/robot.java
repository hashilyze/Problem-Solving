// 로봇
// 생성일: 2025-01-17

import java.io.*;
import java.util.*;

public class robot {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	// Maker
	static final char SPCAE = 'S';
	static final char WALL = 'W';
	static final char ROBOT_A = 'A';
	static final char ROBOT_B = 'B';
	static final char ROBOT_C = 'C';
	
	// Delta
	static final int[] dxA = { 1 };
	static final int[] dyA = { 0 };
	
	static final int[] dxB = { 1, -1 };
	static final int[] dyB = { 0, 0 };
	
	static final int[] dxC = { 1, -1, 0, 0 };
	static final int[] dyC = { 0, 0, 1, -1 };
	
	
	public static void main(String[] args) throws IOException {
		int T = Integer.parseInt(br.readLine());
		for(int t = 1; t <= T; ++t) {
			// Input
			int N = Integer.parseInt(br.readLine());
			
			int[][] mat = new int[N][N];
			for(int i = 0; i < N; ++i) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(int j = 0; j < N; ++j) {
					mat[i][j] = st.nextToken().charAt(0);
				}
			}
			
			// Solution
			int ans = solution(N, mat);
			
			// Output
			bw.append("#" + t + " " + ans + "\n");
			bw.flush();
		}
	}
	
	static int solution(int N, int[][] mat) {
		int ans = 0;
		for(int y = 0; y < N; ++y) {
			for(int x = 0; x < N; ++x) {
				if(mat[y][x] == ROBOT_A) ans += getMovableSapces(y, x, dyA, dxA, N, mat);
				else if(mat[y][x] == ROBOT_B) ans += getMovableSapces(y, x, dyB, dxB, N, mat);
				else if(mat[y][x] == ROBOT_C) ans += getMovableSapces(y, x, dyC, dxC, N, mat);
				
			}
		}
		return ans;
	}
	
	static boolean isMovalbe(int y, int x, int N, int[][] mat) {
		return 0 <= y && y < N && 0 <= x && x < N && mat[y][x] == SPCAE;
	}
	
	static int getMovableSapces(int y, int x, int[] dy, int[] dx, int N, int[][] mat) {
		int ans = 0;
		for(int i = 0; i < dy.length; ++i) {
			for(int d = 1; true; ++d) {
				int ny = y + dy[i] * d;
				int nx = x + dx[i] * d;
				
				if(!isMovalbe(ny, nx, N, mat)) break;
				
				++ans;
			}
		}
		return ans;
	}
}
