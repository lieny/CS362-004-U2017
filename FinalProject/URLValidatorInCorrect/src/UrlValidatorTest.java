/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;





/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(urlVal.isValid("http://www.amazon.com"));
	   System.out.println(urlVal.isValid("http://www.google.com:80?query=answer"));
	   System.out.println(urlVal.isValid("http://oregonstate.edu"));
	   System.out.println(urlVal.isValid("www.google.com"));
	   System.out.println(urlVal.isValid("hpl://www.google.com"));
	   System.out.println(urlVal.isValid("3tt://www.google.com"));
	   System.out.println(urlVal.isValid("http://www.google.come"));
	   System.out.println(urlVal.isValid(""));
	   System.out.println(urlVal.isValid("http://www.google:10000.com"));
	   System.out.println(urlVal.isValid("http://www.google:100.com"));
	   System.out.println(urlVal.isValid("http://www.google:65535.com"));
	   System.out.println(urlVal.isValid("http://www.google:100.com"));
   }
   
 
   public void testScheme()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //Testing different partition
	   String validScheme1 = "http://";
	   String validScheme2 = "ftp://";
	   String invalidScheme1 = "3ht://";
	   String invalidScheme2 = "http/";
	   String emptyScheme = "";		//should be valid
	   
	   //a valid URL without scheme
	   String restOfURL = "www.google.com";
	   
	   //Produce valid URLs
	   String validURL1 = validScheme1 + restOfURL;
	   String validURL2 = validScheme2 + restOfURL;
	   
	   //Produce invalid URLs
	   String invalidURL1 = invalidScheme1 + restOfURL;
	   String invalidURL2 = invalidScheme2 + restOfURL;
	   
	   //Produce URL with empty scheme
	   String emptySchemeURL = emptyScheme + restOfURL;
	   System.out.println("------------------ Testing Scheme ------------------");	   
	   //Test Valid URL
	   if(urlVal.isValid(validURL1))
		   System.out.println(validURL1 + "    :    passed");
	   
	   else
		   System.out.println(validURL1 + "    :    failed");
	   
	   if(urlVal.isValid(validURL2))
		   System.out.println(validURL2 + "    :    passed");
	   
	   else
		   System.out.println(validURL2 + "    :    failed");
	   
	   if(urlVal.isValid(invalidURL1))
		   System.out.println(invalidURL1 + "    :    passed");
	   
	   else
		   System.out.println(invalidURL1 + "    :    failed");
	   
	   if(urlVal.isValid(invalidURL2))
		   System.out.println(invalidURL2 + "    :    passed");
	   
	   else
		   System.out.println(invalidURL2 + "    :    failed");


   }
   public void testAuthority(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
   
   String validScheme = "http://";
   String validAuthority = "www.google.com";
   String validPort = ":80";
   String validPath = "/path";
   String validQuery = "?query=answer";
   
   //testing valid and invalid Authority
   String invalidAuthority = "%$#.com";
   String emptyAuthority = "";
   
   //Put together URLS for testing
   String validURL = validScheme + validAuthority + validPort + validPath + validQuery;
   String invalidURL = validScheme + invalidAuthority + validPort + validPath + validQuery;
   String emptyURL = validScheme + emptyAuthority + validPort + validPath + validQuery;
   
   System.out.println("\nTesting Authority (Second)Partition");
   
   //Testing valid
   if(urlVal.isValid(validURL)) {
	   System.out.println("Testing valid URL: " + validURL);
	   System.out.println("\nTest Passed, returned valid URL");
   }
   else {
	   System.out.println("Testing valid URL: " + validURL);
	   System.out.println("\nTest Failed, returned invalid URL");
   }
   
   //Testing invalid URL
   if(urlVal.isValid(invalidURL)) {
	   System.out.println("Testing invalid URL: " + invalidURL);
	   System.out.println("\nTest Failed, returned valid URL");
   }
   else {
	   System.out.println("Testing invalid URL: " + invalidURL);
	   
   }
   
   //Testing empty
   if(urlVal.isValid(emptyURL)) {
	   System.out.println("Testing empty URL: " + emptyURL);
	   System.out.println("\nTest Failed, returned valid URL (empty Authority is invalid)");
   }
   else {
	   System.out.println("Testing empty URL: " + emptyURL);
	   System.out.println("\nTest Passed, returned invalid URL (empty Authority = invalid");
   }
   
}

   public void testPort(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //valid ports
	   String validPort1 = ":80";
	   String validPort3 = ":1000";
	   String validPort2 = ":65535";
	   
	   //Invalid ports
	   String invalidPort1 = ":-1";
	   String invalidPort2 = ":65a";
	   
	   //empty port - should be valid
	   String emptyPort = "";
	   
	   String restOfURL = "http://www.google.com";
	 //Produce valid URLs
	   String validURL1 = restOfURL + validPort1;
	   String validURL2 = restOfURL + validPort2;
	   String validURL3 = restOfURL + emptyPort;
	   String validURL4 = restOfURL + validPort3;
	   
	   //produce invalid URLs
	   String invalidURL1 = restOfURL + invalidPort1;
	   String invalidURL2 = restOfURL + invalidPort2;
	   
	   System.out.println("------------------ Testing Port ------------------");
	   if(urlVal.isValid(validURL1))
		   System.out.println(validURL1 + "    :    passed");
	   else
		   System.out.println(validURL1 + "    :    failed");
	   
	   if(urlVal.isValid(validURL2))
		   System.out.println(validURL2 + "    :    passed");	   
	   else
		   System.out.println(validURL2 + "    :    failed");
	  
	   if(urlVal.isValid(validURL3))
		   System.out.println(validURL3 + "    :    passed");	   
	   else
		   System.out.println(validURL3 + "    :    failed");
	  
	   if(urlVal.isValid(validURL4))
		   System.out.println(validURL4 + "    :    passed");	   
	   else
		   System.out.println(validURL4 + "    :    failed");
	   
	   if(urlVal.isValid(invalidURL1))
		   System.out.println(invalidURL1 + "    :    passed");   
	   else
		   System.out.println(invalidURL1 + "    :    failed");
	   
	   if(urlVal.isValid(invalidURL2))
		   System.out.println(invalidURL2 + "    :    passed");  
	   else
		   System.out.println(invalidURL2 + "    :    failed");
   }
   
   public void testPath(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String validScheme = "http://";
	   String validAuthority = "www.google.com";
	   String validPort = ":80";
	   String validPath = "/path";
	   String validQuery = "?query=answer";
	   
	   //testing valid and invalid Port
	   String invalidPath = "////";
	   String emptyPath = "";
	   
	   //Put together URLS for testing
	   String validURL = validScheme + validAuthority + validPort + validPath + validQuery;
	   String invalidURL = validScheme + validAuthority + validPort + invalidPath + validQuery;
	   String emptyURL = validScheme + validAuthority + validPort + emptyPath + validQuery;
	   
	   System.out.println("\nTesting Path (Fourth)Partition");
	   
	   //Testing valid
	   if(urlVal.isValid(validURL)) {
		   System.out.println("Testing valid URL: " + validURL);
		   System.out.println("\nTest Passed, returned valid URL");
	   }
	   else {
		   System.out.println("Testing valid URL: " + validURL);
		   System.out.println("\nTest Failed, returned invalid URL");
	   }
	   
	   //Testing invalid URL
	   if(urlVal.isValid(invalidURL)) {
		   System.out.println("Testing invalid URL: " + invalidURL);
		   System.out.println("\nTest Failed, returned valid URL");
	   }
	   else {
		   System.out.println("Testing invalid URL: " + invalidURL);
		   
	   }
	   
	   //Testing emtpy
	   if(urlVal.isValid(emptyURL)) {
		   System.out.println("Testing empty URL: " + emptyURL);
		   System.out.println("\nTest Failed, returned invalid URL");
	   }
	   else {
		   System.out.println("Testing empty URL: " + invalidURL);
		   System.out.println("\nTest Passed, returned valid URL");
	   }
	   
   }

   public void testQuery(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String validScheme = "http://";
	   String validAuthority = "www.google.com";
	   String validPort = ":80";
	   String validPath = "/path";
	   String validQuery = "?query=answer";
	   
	   //testing valid and invalid Port
	   String invalidQuery = "thisisthequery";
	   String emptyQuery = "";
	   
	   //Put together URLS for testing
	   String validURL = validScheme + validAuthority + validPort + validPath + validQuery;
	   String invalidURL = validScheme + validAuthority + validPort + validPath + invalidQuery;
	   String emptyURL = validScheme + validAuthority + validPort + validPath + emptyQuery;
	   
	   System.out.println("\nTesting Port (Third)Partition");
	   
	   //Testing valid
	   if(urlVal.isValid(validURL)) {
		   System.out.println("Testing valid URL: " + validURL);
		   System.out.println("\nTest Passed, returned valid URL");
	   }
	   else {
		   System.out.println("Testing valid URL: " + validURL);
		   System.out.println("\nTest Failed, returned invalid URL");
	   }
	   
	   //Testing invalid URL
	   if(urlVal.isValid(invalidURL)) {
		   System.out.println("Testing invalid URL: " + invalidURL);
		   System.out.println("\nTest Failed, returned valid URL");
	   }
	   else {
		   System.out.println("Testing invalid URL: " + invalidURL);
		   
	   }
	   
	   //Testing emtpy
	   if(urlVal.isValid(emptyURL)) {
		   System.out.println("Testing empty URL: " + emptyURL);
		   System.out.println("\nTest Failed, returned invalid URL");
	   }
	   else {
		   System.out.println("Testing empty URL: " + emptyURL);
		   System.out.println("\nTest Passed, returned valid URL");
	   }
	   
   }

   public boolean testGeneric(String scheme, String authority, String port, String path, String query)
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //Put together URLS for testing
	   String URL = scheme + authority + port + path + query;
	   
	   //Testing valid
	   if(urlVal.isValid(URL)) 
	   {
		   return true;
	   }
	   else 
	   {
		   return false;
	   }
   }

  
public void testIsValid()
   {
       //Lets start out with a valid URL,
	   String validScheme = "http://";
	   String validAuthority = "www.google.com";
	   String validPort = ":80";
	   String validPath = "/path";
	   String validQuery = "?query=answer";
	   
	   //Now lets change the URL until the test returns something invalid
	   
	   //First test path
	   for (int i = 0; i < 10000; i++)
	   {
	       String newPath = validPath + String.valueOf(i);
	       if (testGeneric(validScheme, validAuthority, validPort, newPath, validQuery) ==  false)
	       {
	           System.out.println("Error with testing path");
	       }
	   }
   }
   
  
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}
