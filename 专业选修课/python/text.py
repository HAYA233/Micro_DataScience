import re
text = input()
text = re.sub("暴力", "**", text)
text = re.sub("色情", "**", text)
text = re.sub("其他关键词", "**", text)
print(text)
