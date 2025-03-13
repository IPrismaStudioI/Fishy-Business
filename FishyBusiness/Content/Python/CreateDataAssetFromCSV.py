import unreal
import pandas as pd
import re


def camel_to_snake(name):
    """Converte CamelCase in snake_case (es. 'HealthPoints' -> 'health_points')."""
    name = re.sub(r'(?<!^)(?=[A-Z])', '_', name).lower()
    return name

def create_data_assets_from_csv(csv_file, asset_class, package_path):
    """
    Crea più Data Asset in Unreal Engine, uno per ogni riga valida del CSV.

    :param csv_file: Percorso del file CSV.
    :param asset_class: Classe del Data Asset (es. unreal.MyDataAsset).
    :param package_path: Percorso della cartella degli asset (es. "/Game/DataAssets").
    """
    
    df = pd.read_csv(csv_file)
    
    dialogueIndexList = []
    dialogueIndexList.append(1)

    for i in range(df.shape[0]):
        if pd.isnull(df.iloc[i].iloc[0]):
            dialogueIndexList.append(i + 1)
            
    print(dialogueIndexList)
        
    for startDialoguePtr in dialogueIndexList:
        bIsLastDialogue = False
        row = df.iloc[startDialoguePtr]
        asset_name = str(row.iloc[0]).strip()
        asset_full_path = f"{package_path}/{asset_name}"
        #print(asset_full_path)
        if unreal.EditorAssetLibrary.does_asset_exist(asset_full_path):
            asset = unreal.EditorAssetLibrary.load_asset(asset_full_path)
        else:
            factory = unreal.DataAssetFactory()
            asset = unreal.AssetToolsHelpers.get_asset_tools().create_asset(
                asset_name,
                package_path,
                asset_class,
                factory
            )
            
        try:
            actualIndex = dialogueIndexList.index(startDialoguePtr)
            actualValue = dialogueIndexList[actualIndex]
            nextValue = dialogueIndexList[actualIndex + 1]
            endDialoguePtr = nextValue - 2
        except:
            endDialoguePtr = df.shape[0] - 1
            bIsLastDialogue = True
            
        # print(startDialoguePtr)
        # print(endDialoguePtr)

        lenghtDialogue = endDialoguePtr - startDialoguePtr + 1
        
        ListLines = []
        for i in range(lenghtDialogue):
            listTmp = unreal.Line()
            listTmp.s_pg_name = str(df.iloc[startDialoguePtr + i].iloc[1]).strip()
            listTmp.s_sentence = str(df.iloc[startDialoguePtr + i].iloc[2]).strip()
            ListLines.append(listTmp)
        
        print(ListLines)
        
        i = 0
        while i < len(ListLines):
            name = ListLines[i].s_pg_name
            j = i + 1

            sentencesList = []
            sentence = unreal.Sentence()
            sentence.s_sentence = ListLines[i].s_sentence
            sentencesList.append(sentence)

            while j < len(ListLines):
                if ListLines[j].s_pg_name != "nan" : 
                    break
                sentenceNoName = unreal.Sentence()
                sentenceNoName.s_sentence = ListLines[j].s_sentence
                sentencesList.append(sentenceNoName)
                j = j + 1

            if j - 1 != i: 
                j = j - 1
                i = j


            monologueTmp = unreal.Monologue()
            monologueTmp.s_name = name
            monologueTmp.s_sentences = sentencesList

            asset.dialogue.x_dialogue_parts.append(monologueTmp)

            i = i + 1


            #print(ListLines[i])
        

    

def testing():
    #testing unreal.py
    test = unreal.Monologue()
    test.s_name = "x"
    test3 = []
    for i in range(2):
        test1 = unreal.Sentence()
        test1.s_sentence = "ciao"
        test3.append(test1)
    
    
    test.s_sentences = test3
    print(test)

    #testing sorting dialogue ptrs
    print(df.iloc[ptr])

def old_creation(df):
    for _, row in df.iterrows():
        asset_name = str(row.iloc[0]).strip()  # Primo valore della riga = nome del Data Asset
        asset_full_path = f"{package_path}/{asset_name}"

        # Controllo per saltare le righe con la prima colonna nulla o vuota
        if not asset_name:
            continue

        if unreal.EditorAssetLibrary.does_asset_exist(asset_full_path):
            asset = unreal.EditorAssetLibrary.load_asset(asset_full_path)
            fill_asset(asset, row, df)
            continue
            #print(f"L'asset '{asset_full_path}' esiste già, salto...")
        else:
            # Crea il Data Asset
            factory = unreal.DataAssetFactory()
            asset = unreal.AssetToolsHelpers.get_asset_tools().create_asset(
                asset_name,
                package_path,
                asset_class,
                factory
            )

        if not asset:
            print(f"Errore nella creazione del Data Asset: {asset_name}")
            continue

        fill_asset(asset, row, df)

        # Salva l'asset
        unreal.EditorAssetLibrary.save_asset(asset_full_path)
        print(f"✅ Data Asset creato: {asset_full_path}")

def fill_asset(asset, row, df):
    # Inserisce i dati nei campi del Data Asset
    for col_name, value in row.items():
        if col_name == df.columns[0]:  # Ignora la colonna del nome
            continue

        property_name = camel_to_snake(col_name.strip())  # Normalizza il nome
        try:
            asset.set_editor_property(property_name, value)
        except Exception as e:
            print(f"Errore nell'impostare {property_name} per {asset_name}: {e}")

# Esempio di utilizzo
if __name__ == "__main__":
    asset_class = unreal.UDA_Dialogue  # Sostituisci con la tua classe C++
    package_path = "/Game/DataAssets"
    asset_name = "MyDataAssetInstance"
    properties = {
        "Value": 42,
        "Name": "My Example Data"
    }

    #create_data_assets_from_csv(csv_file, asset_class, package_path)
