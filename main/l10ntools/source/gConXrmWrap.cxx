/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/
using namespace std;
#include "gConXrm.hxx"



/*****************************************************************************
 *********************   G C O N X R M W R A P . C X X   *********************
 *****************************************************************************
 * This includes the c code generated by flex
 *****************************************************************************/



/**********************   I M P L E M E N T A T I O N   **********************/
#include "gConXrm_yy.c"



/**********************   I M P L E M E N T A T I O N   **********************/
void convert_xrm_impl::runLex()
{
  genXrm_lex();

  // write last part of file.
  if (mbMergeMode)
    writeSourceFile(msCollector);
}



/**********************   I M P L E M E N T A T I O N   **********************/
void convert_xrm_impl::startCollectData(string& sType, string& sCollectedText)
{
  if (mbMergeMode)
    writeSourceFile(msCollector+sCollectedText);
  msCollector.clear();

  mbCollectingData = true;
  msMergeType      = sType;
  msTag            = sCollectedText;
}



/**********************   I M P L E M E N T A T I O N   **********************/
void convert_xrm_impl::stopCollectData(string& sType, string& sCollectedText)
{
  string sKey;
  int    nL;


  // check tag match
  if (sType != msMergeType)
	throw "Conflicting tags: " + msTag + msCollector + sCollectedText;

  // locate key and extract it
  nL    = msTag.find("id=") +4;
  sKey  = msTag.substr(nL, msTag.find("\"", nL+1) - nL);

  if (mbMergeMode)
  {
    // get all languages (includes en-US)
    vector<l10nMem_entry *>& cExtraLangauges = mcMemory.getLanguagesForKey(sKey);
    string                   sNewLine;
    int                      nL = cExtraLangauges.size();

	// write en-US entry
    writeSourceFile(msCollector+sCollectedText);

	// and all other languages for that key
	for (int i = 0; i < nL; ++i)
    {
      sNewLine = "\n<" + sType + " id=\"" + sKey + "\"" + " xml:lang=\"" +
                 cExtraLangauges[i]->msLanguage + "\">" +
                 cExtraLangauges[i]->msText +
                 "</" + sType + ">";

      writeSourceFile(sNewLine);
    }
  }
  else
    mcMemory.setEnUsKey(sKey, msCollector);

  mbCollectingData = false;
  msCollector.clear();
}  


/**********************   I M P L E M E N T A T I O N   **********************/
void convert_xrm_impl::collectData(string& sCollectedText)
{
  msCollector += sCollectedText;
  if (sCollectedText == "\n")
  {
    if (mbMergeMode)
      writeSourceFile(msCollector);
    msCollector.clear();
  }
}
