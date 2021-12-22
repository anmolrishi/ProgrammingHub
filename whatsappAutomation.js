const {Builder, By, Key, until, WebElement} = require('selenium-webdriver');

(async function example() {
    let driver = await new Builder().forBrowser('chrome').build();
    try {
        // await driver.get('https://www.fedex.com/apps/fedextrack/?action=track&trackingnumber=787643512567&cntry_code=us&locale=en_US');
        await driver.get('https://web.whatsapp.com/');
        // await driver.get(`https://www.google.com`)
        // await driver.findElement(By.id('container'))
        // let firstResult={};
        // setTimeout(() => {firstResult = driver.wait(until.elementLocated(By.id('container')),10000)},10000)
        // let firstResult = await driver.wait(until.elementLocated(By.xpath('//*[@id="container"]/div/div/div[2]/div/div[1]/div[2]/div[3]/div/div[3]/div/div[2]/div[1]/div[5]/div/div[4]/div/div[2]/div/ul[1]')),20000)
        
        // let firstResult = await driver.wait(until.elementLocated(By.xpath('//*[@id="container"]/div/div/div[2]/div/div[1]/div[2]/div[3]/div/div[3]/div/div[1]/div/div[6]/div[2]/div/p[4]')),100000)

        // let secondResult = await driver.wait(until.elementLocated(By.xpath('//*[@id="container"]/div/div/div[2]/div/div[1]/div[2]/div[3]/div/div[3]/div/div[2]/div[1]')),100000)

        // let secondResult = await driver.wait(until.elementLocated(By.xpath('//*[@id="container"]/div/div/div[2]/div/div[1]/div[2]/div[3]/div/div[3]/div/div[2]/div[1]/div[5]')),5000)
        let open = new WebElement();
        open = await driver.wait(until.elementLocated(By.className('_3FRCZ')),100000)
        
        // return driver.wait(function() {
        //     return driver.findElement(By.id('container')).isDisplayed();
        // }, 10000);


        // console.log(await firstResult.getText());
        // console.log(await secondResult.getText());
        // console.log(await open.getText());
        // await open.click();
        await open.sendKeys('Papa');
        await open.sendKeys(Key.ENTER);
        

        let text = new WebElement();
        text = await driver.wait(until.elementLocated(By.className('_2UL8j')),200000)
        await text.sendKeys('Hello')
        
        text = await driver.wait(until.elementLocated(By.className('_1U1xa')),100000)
        await text.sendKeys(Key.ENTER)


        await open.sendKeys('self');
        await open.sendKeys(Key.ENTER);
        

       text = new WebElement();
        text = await driver.wait(until.elementLocated(By.className('_13mgZ')),100000)
        await text.sendKeys('Welcome to the world of automation')
        
        text = await driver.wait(until.elementLocated(By.className('_3M-N-')),100000)
        await text.sendKeys(Key.ENTER)

        
        
        
    } finally {
        // await driver.quit();
    }
})();


