import re

def preparse():
    print("==== PREPARSING ====")
    print("Removing comments and whitespaces")
    content = open("input.iv", "r").read().replace("\r", " ")
    # we need to remove all comments that are between two # symbols
    content = re.sub(r"#.*#", "", content)
    content = content.replace("\n", " ").replace("\t", " ")
    # we remove every 2 spaces in a row
    while "  " in content:
        content = content.replace("  ", " ")
    # first we change words to numbers
    keywords = [
        "DIS",
        "SET",
        "CPY",
        "TRC",
        "ADD",
        "SUB",
        "MUL",
        "DIV",
        "AND",
        "HOR",
        "NOT",
        "SUP",
        "EQU",
        "JMP",
        "GIF",
        "SCT",
        "HLT",
    ]
    print("Changing keywords : ", end="")
    changed_keywords = 0
    for i, keyword in enumerate(keywords):
        content = content.replace(keyword, str(i))
        changed_keywords += 1
    print(f"Changed {changed_keywords} keywords")
    print("Looking for functions")
    procedures = {}
    procedure_buffer = []
    while 1:
        # we get procedures : it's a word that end with :, then the content of the procedure and then an "END"
        # we get the name of the procedure
        procedure_name = re.search(r"([a-zA-Z0-9_]+):", content)
        if procedure_name is None:
            break
        procedure_name = procedure_name[1]
        # we get the content of the procedure
        procedure_content = re.search(rf"{procedure_name}:(.*?)END", content, re.DOTALL)
        if procedure_content is None:
            raise Exception(f"Procedure {procedure_name} is not closed")
        procedure_content = procedure_content[1]
        # we remove the procedure from the content
        content = content.replace(f"{procedure_name}:{procedure_content}END", "")
        # we add the procedure to the procedures dict
        procedures[procedure_name] = procedure_content.strip()
    print(f"Found {len(procedures)} procedures")
    
    

    open("input.ivr", "w").write(content)