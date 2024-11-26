package com.example.demo.api.dto;

import java.util.ArrayList;
import java.util.List;

import com.fasterxml.jackson.annotation.JsonProperty;

import lombok.AccessLevel;
import lombok.Builder;
import lombok.Data;
import lombok.experimental.FieldDefaults;

@Data
@Builder
@FieldDefaults(level=AccessLevel.PRIVATE)
public class requestDto {
	@JsonProperty("ans")
	List<Long> ans=new ArrayList<>();

	public List<Long> getans(){
		return ans;
	}
}
