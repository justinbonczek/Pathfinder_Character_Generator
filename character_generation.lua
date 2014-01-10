--Generates a random value for each ability score
--Returns 6 values, one for each score generated
function GenerateAbilityScores()
	math.randomseed(os.time())
	math.random(); math.random(); math.random()
	local primary = math.random(15, 17)
	local secondary = math.random(12, 15)
	local tertiary = math.random(11, 14)
	local average = math.random(9, 12)
	local poor = math.random(8, 10)
	local awful = math.random(7, 9)
	
	return primary, secondary, tertiary, average, poor, awful
end

--Generates a random value for race and class that correspond to an enum in C
--Returns 2 values, once for each generated number
function GenerateRaceAndClass()
	math.randomseed(os.time())
	math.random(); math.random(); math.random();
	local raceValue = math.random(7) - 1
	local classValue = math.random(11) - 1
	
	return raceValue, classValue
end