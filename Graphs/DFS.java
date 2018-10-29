import java.io.File;

class FileUtils
{
	public static void listFilesRecursive(File root)
	{
		File[] listOfFilesAndDirectory = root.listFiles();

		if (listOfFilesAndDirectory != null)
		{
			for (File file : listOfFilesAndDirectory)
			{
				if (file.isDirectory()) {
					listFilesRecursive(file);
				}
				else {
					System.out.println(file);
				}
			}
		}
	}

	public static void main(String args[])
	{
		String dir = "C:\\Users";
		File rootDir = new File(dir);

		listFilesRecursive(rootDir);
	}
}
