package com.example.demo.api.controller;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import com.example.demo.api.dto.ansDto;
import com.example.demo.api.dto.requestDto;
import com.example.demo.api.service.numService;

@RestController
@RequestMapping("/api")
public class mainComtroller {
	
	@Autowired
	private numService service;
	
	
	@PostMapping("/find")
	public ResponseEntity<?> findFactors(@RequestParam(name="num")String n){
		
		Long num=10L;
		
		try {
			num=Long.parseLong(n);
			
			
		}catch(Exception e) {
			e.printStackTrace();
		}
		
		
		List<Long> factors=new ArrayList<Long>();
		
		for(int i=1;i<=num;i++) {
			factors.add(service.getFactors(i));
		}
		
		ansDto ans=new ansDto();
		ans.setAns(factors);
		
		return ResponseEntity.ok(ans);
		
	}
	
	@PostMapping("/delete")
	public ResponseEntity<?> deleteDuplicates(@RequestBody requestDto dto){
		List<Long> result = service.eraseDuplicates(dto.getans());
		result.forEach(System.out::println);
		ansDto ans = new ansDto();
		ans.setAns(result);
		return ResponseEntity.ok(ans);
	}
	
	

}
