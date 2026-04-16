// 사방탐색1
// 생성일: 2025-01-16

import java.io.*;
import java.util.*;

public class FourWay1 {
	static final int[] dx = {1, -1, 0, 0};
	static final int[] dy = {0, 0, 1, -1};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int R = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
		
		int[][] mat = new int[R][C];
		for(int y = 0; y < R; ++y) {
			for(int x = 0; x < C; ++x) {
				st = new StringTokenizer(br.readLine());
				mat[y][x] = Integer.parseInt(st.nextToken());
			}
		}
		System.out.println("총합: " + solution(R, C, mat));
	}
	
	static boolean isValid(int y, int x, int R, int C) {
		return 0 <= y && y < R && 0 <= x && x < C;
	}
	static int solution(int R, int C, int[][] mat) {
		int ans = 0;
		for(int y = 0; y < R; ++y) {
			for(int x = 0; x < C; ++x) {
				if(mat[y][x] != 0) continue;
				
				for(int i = 0; i < 4; ++i) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if(isValid(ny, nx, R, C)) {
						ans += mat[ny][nx];
					}
				}
			}
		}
		return ans;
	}
}