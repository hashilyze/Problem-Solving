// [Beakjoon] 2720. 세탁소 사장 동혁
// https://www.acmicpc.net/problem/2720

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	static final int[] UNITS = {25, 10, 5, 1};
	
	
	public static void main(String[] args) throws IOException {
		// Input
		int T = Integer.parseInt(br.readLine());
		
		while(T-- > 0) {
			int[] changes = new int[4];
			int C = Integer.parseInt(br.readLine());
			
			// Solution
			for(int i = 0; i < UNITS.length; ++i) {
				changes[i] = C / UNITS[i];
				C %= UNITS[i];
			}
			
			for(int e : changes) bw.append(e + " ");
			bw.append('\n');
		}
		
		// Output
		bw.flush();
	}
}
