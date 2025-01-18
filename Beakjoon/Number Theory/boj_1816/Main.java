// [Beakjoon] 1816. 암호 키
// https://www.acmicpc.net/problem/1816

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	static final int SIZE = 1_000_000;
	static int[] lpfs;
	static List<Integer> primes;
	
	
	public static void main(String[] args) throws IOException {
		initEuler(SIZE);
		int N = Integer.parseInt(br.readLine());
		
		while(N-- > 0) {
			// Input
			long S = Long.parseLong(br.readLine());
			
			// Solution
			boolean isGoodPw = true;
			for(int p : primes) { 
				if(S % p == 0) {
					isGoodPw = false;  // 1_000_000 이하의 소인수를 포함하면 부적합
					break;
				}
			}
			
			// Output
			bw.append(isGoodPw ? "YES\n" : "NO\n");
		}
		bw.flush();
	}
	
	// 오일러 체 초기화
	static void initEuler(int N) {
		lpfs = new int[N + 1];
		primes = new ArrayList<>();
		
		
		for(int i = 2; i <= N; ++i) {
			if(lpfs[i] == 0) {
				lpfs[i] = i;
				primes.add(i);
			}
			
			for(int p : primes) {
				if((long)i * p > N) break;
				lpfs[i * p] = p;
				if(i % p == 0) break;
			}
		}
	}
}
