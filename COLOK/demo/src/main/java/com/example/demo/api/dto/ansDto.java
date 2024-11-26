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
public class ansDto {
	@JsonProperty("nums")
	List<Long> ans=new ArrayList<>();

	public void setAns(List<Long> factors) {
		this.ans=factors;
		
	}

}
