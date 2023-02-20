from dataclasses import dataclass
from typing import Optional
import re

@dataclass
class Part:
    value: str
    index: int = 0

def preparse():
    print("==== PREPARSING ====")
    content = open("input.iv", "r").read().replace("\r", " ")
    
    # we need to remove all comments that are between two # symbols
    content = re.sub(r"#.*#", "", content)
    content = content.replace("\n", " ").replace("\t", " ")
    
    # we remove every 2 spaces in a row
    while "  " in content:
        content = content.replace("  ", " ")
    part_list = []
    for i, part in enumerate(content.split(" ")):
        if part == "": continue
        part_list.append(Part(part, i))

    # we loop through the list and look for GOTO and GOTOIF
    i = 0
    while i < len(part_list):
        part = part_list[i]
        if part.value == "GOTO":
            # wee remove the GOTO
            part_list.pop(i)
            # we need to find the label
            label = part_list[i]
            part_list.pop(i)
            # we need to find the label in the list
            print(f"GOTO {label.value}")
            goto_command = f"SET 0 {label.value} JMP 0"
            for command in goto_command.split(" "):
                part_list.insert(i, Part(command, 0))
                i += 1
        elif part.value == "GOTOIF":
            # wee remove the GOTOIF
            part_list.pop(i)
            # we need to find the label
            memory = part_list[i]
            part_list.pop(i)
            label = part_list[i]
            part_list.pop(i)
            # we need to find the label in the list
            print(f"GOTOIF {label.value}")
            goto_command = f"SET 0 {label.value} GIF {memory.value} 0"
            for command in goto_command.split(" "):
                part_list.insert(i, Part(command, 0))
                i += 1
        else:
            i += 1

    # we reindex the list
    for i, part in enumerate(part_list):
        part.index = i

    # we collect the index of the labels
    labels = {}
    for i, part in enumerate(part_list):
        if part.value.endswith(":"):
            labels[part.value[:-1]] = part.index
            part_list.pop(i)

    # we reindex the list
    for i, part in enumerate(part_list):
        part.index = i

    # we replace the labels with their index
    for part in part_list:
        if part.value in labels:
            part.value = str(labels[part.value])
    
    # we replace keywords with their number
    keywords = ["DIS","SET","CPY","TRC","ADD","SUB","MUL","DIV","AND","HOR","NOT","SUP","EQU","JMP","GIF","SCT","HLT",]
    for part in part_list:
        if part.value in keywords:
            part.value = str(keywords.index(part.value))
    
    print(part_list)
    
    # we remake the content
    content = " ".join([part.value for part in part_list])
    
    open("input.ivr", "w").write(content)