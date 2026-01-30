import re

file= open("brilcalc.log", "r")
text = file.read() 

match = re.search(
    r"#Summary:\s*\n"
    r"\+.*?\n"   
    r"\|[^\n]*\n"
    r"\+.*?\n"                    
    r"\|[^\n]*\|\s*([\d.]+)\s*\|",
    text
)

print(match.group(1))
totrecorded_pb = float(match.group(1))

totrecorded_fb = totrecorded_pb / 1e3

print(f"Integrated luminosity: {totrecorded_fb:.2f} fb^{-1}")


