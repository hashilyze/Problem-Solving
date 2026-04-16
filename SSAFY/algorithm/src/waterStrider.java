// 소금쟁이
// 생성일: 2025-01-17

import java.io.*;
import java.util.*;

public class waterStrider {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	static final int[] JUMPS = {0, 3, 2, 1};
	static final int DOWN = 1;
	static final int RIGHT = 2;
	static final int[] dx = {0, 1};
	static final int[] dy = {1, 0};
	
	public static void main(String[] args) throws IOException {
		int T = Integer.parseInt(br.readLine());
		for(int t = 1; t <= T; ++t) {
			// Input
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken()); // 연못의 크기
			int M = Integer.parseInt(st.nextToken()); // 소금쟁이의 수
			
			int[][] bugs = new int[M][3]; // (posY, posX, dir)
			for(int i = 0; i < M; ++i) {
				st = new StringTokenizer(br.readLine());
				bugs[i][0] = Integer.parseInt(st.nextToken()); // posY
				bugs[i][1] = Integer.parseInt(st.nextToken()); // posX
				bugs[i][2] = Integer.parseInt(st.nextToken()); // dir
			}
			
			bw.append("#" + t + ' ' + solution(N, M, bugs) + '\n');
			bw.flush();
		}
	}
	
	static int solution(int N, int M, int[][] bugs) {
		boolean[][] pool = new boolean[N][N];
		for(int i = 0; i < M; ++i) {
			int y = bugs[i][0];
			int x = bugs[i][1];
			int d = bugs[i][2];
			
			for(int j = 0; j < JUMPS.length; ++j) {
				int ny = y + dy[d - 1] * JUMPS[j];
				int nx = x + dx[d - 1] * JUMPS[j];
				if(isValid(ny, nx, N)) {
					if(pool[ny][nx]) {
						return i + 1;
					}
					y = ny;
					x = nx;
					pool[y][x] = true;
				} else { 
					break; // 연못 이탈
				}
			}
		}
		
		return 0; // 만족하는 케이스 없음
	}
	
	static boolean isValid(int y, int x, int N) {
		return 0 <= y && y < N && 0 <= x && x < N; 
	}

}
