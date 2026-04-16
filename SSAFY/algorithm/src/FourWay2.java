// 사방탐색2
// 생성일: 2025-01-16

import java.util.Scanner;

public class FourWay2 {
	static final int[] dx = {1, -1, 0, 0};
	static final int[] dy = {0, 0, 1, -1};
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int R = scanner.nextInt();
		int C = scanner.nextInt();
		
		char[][] mat = new char[R][C];
		for(int y = 0; y < R; ++y) {
			for(int x = 0; x < C; ++x) {
				mat[y][x] = scanner.next().charAt(0);
			}
		}
		System.out.println("총합: " + solution(R, C, mat));
		scanner.close();
	}
	
	static boolean isValid(int y, int x, int R, int C) {
		return 0 <= y && y < R && 0 <= x && x < C;
	}
	static int solution(int R, int C, char[][] mat) {
		int ans = 0;
		for(int y = 0; y < R; ++y) {
			for(int x = 0; x < C; ++x) {
				if(mat[y][x] != 'X') continue;
				
				for(int i = 0; i < 4; ++i) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if(isValid(ny, nx, R, C) && mat[ny][nx] != 'X') {
						ans += mat[ny][nx] - '0';
						mat[ny][nx] = '0';
					}
				}
			}
		}
		return ans;
	}
}
