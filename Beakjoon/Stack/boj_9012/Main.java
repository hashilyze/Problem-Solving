// [Beakjoon] 9012. 괄호
// https://www.acmicpc.net/problem/9012

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		int N = Integer.parseInt(br.readLine());
		
		while(N-- > 0) {
			// Input
			char[] ps = br.readLine().toCharArray();
			
			// Solution
			int opened = 0;
			for(char ch : ps) {
				if(ch == '(') {
					++opened;
				} else { // ch == ')'
					--opened;
					if(opened < 0) break;
				}
			}
			
			// Output
			bw.append(opened == 0? "YES\n" : "NO\n");
		}
		bw.flush();
	}
}
