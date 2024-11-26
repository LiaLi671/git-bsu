package com.example.demo.api.service;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

import org.springframework.stereotype.Service;

@Service
public class numService {

	public long getFactors(int n) {
		long fact=1;
		for(int i=1;i<=n;i++) {
				fact=fact*i;
		}
		return fact;
	}
	
	public List<Long> eraseDuplicates(List<Long> array){
		Set<Long> set = new HashSet<>();
		for(Long i:array) {
			set.add(i);
		}
		return set.stream().toList();
	}
	
	
	
}
